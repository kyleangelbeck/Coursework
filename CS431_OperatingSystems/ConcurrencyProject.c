#include <semaphore.h>
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

// total number of customers
#define NUM_CUSTOMERS 10

// maximum length of the line waiting for service
// when 1 person is being served, and 2 more are 
// waiting, new customers will leave
#define MAX_OCCUPANCY 2

// variable to track the number of customers in line
int waiting = 0;
// variable to track number of customers who left the shop
int left = 0;

// you'll also need some semaphores (at least 3)
// declare them globally and then initialize them in main()
sem_t sem_waiting;
sem_t sem_barista;
sem_t sem_customer;

// 1. one to safely update the shared variable waiting
// 2. one to signal customers
// 3. one to signal the barista


// simulate time passing
long random();
void random_wait(int time)
{
  int length = random() % time;
  sleep(length);
}


void *barista_thread(void *args)
{
  int served = 0;

  // only serve the number of customers that we expect 
  // in this run, then close the cafe
  while(served < NUM_CUSTOMERS - left) {
    // Wait for a customer to arrive
    // take the customer from the line
    sem_wait(&sem_barista);

    // make a coffee
    random_wait(7);

    served += 1;

    sem_wait(&sem_waiting);
    waiting--;
    sem_post(&sem_waiting);
    
    //free customer lock
    sem_post(&sem_customer);
  }

  pthread_exit(0);
}


void *customer_thread(void *arg)
{
  int i = *((int *)arg);

  /* wait a random time before going to the cafe */
  random_wait(10);

  // Each customer should try to get one (1) coffee
  if (waiting >= MAX_OCCUPANCY) 
  {
    printf("[Customer %d] **** leaving. ****\n", i);
    sem_wait(&sem_waiting);
    left++;
    sem_post(&sem_waiting);
    pthread_exit(0);
  } else {
    // join the line to get a coffee
    // signal the barista in case I'm the only customer here
    // wait for my coffee

    //increment number of waiting customers
    sem_wait(&sem_waiting);
    waiting++;
    sem_post(&sem_waiting);

    //wait for customer lock
    sem_wait(&sem_customer);
    //signal barista
    sem_post(&sem_barista);

  printf("[Customer %d] **** served. ****\n", i);

  }
  pthread_exit(0);
}


int main()
{
  // seed the random number generator
  srandom(2688);

  //initializing semaphores
  sem_init(&sem_waiting, 0, 1);
  sem_init(&sem_barista, 0, 0);
  sem_init(&sem_customer, 0, 1);

  pthread_t barista;
  pthread_create(&barista, NULL, barista_thread, NULL);

  printf("Creating %d customer threads.\n", NUM_CUSTOMERS);

  pthread_t customers[NUM_CUSTOMERS];

  for(int i = 0; i < NUM_CUSTOMERS; i++)
  {
    pthread_create(&customers[i], NULL, customer_thread, (void *)&i);
  }

  for(int i = 0; i < NUM_CUSTOMERS; i++)
  {
    pthread_join(customers[i], NULL);
  }

  pthread_join(barista, NULL);
  printf("The cafe is now closed!\n");
  
  exit(0);
}