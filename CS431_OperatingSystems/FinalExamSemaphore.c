#include <semaphore.h>
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

//N spaces
int spaces;
int parked = 0;

sem_t sem_entrygate;
sem_t sem_exitgate;
sem_t sem_globalupdate;

// simulate time passing
long random();
void random_wait(int time)
{
    int length = random() % time;
    sleep(length);
}

void *car_thread(void *arg) {
    int i = *((int *)arg);

    // wait a random time before going to the garage
    random_wait(10);
    if(parked >= spaces) {
        printf("[Car %d] **** leaving. ****\n", i);
        pthread_exit(0);
    } else {
        //only 2 cars in entrygate at a time
        sem_wait(&sem_entrygate);
        //update parked
        sem_wait(&sem_globalupdate);
        parked++;
        sem_post(&sem_globalupdate);
        sem_post(&sem_entrygate);
        printf("[Car %d] Entered Parking Garage\n", i);


        random_wait(10);

        //only 2 cars in exitgate at a time
        sem_wait(&sem_exitgate);
        //update parked
        sem_wait(&sem_globalupdate);
        parked--;
        sem_post(&sem_globalupdate);
        sem_post(&sem_exitgate);
        printf("[Car %d] Exited Parking Garage\n", i);

        pthread_exit(0);
    }
}

int main() {
    //N spaces
    printf("How many spaces are in the garage?\n");
    scanf("%d", &spaces);

    //how many cars
    int cars;
    printf("How many cars should try to enter the garage?\n");
    scanf("%d", &cars);


    // seed the random number generator
    srandom(2688);

    //initializing semaphores
    sem_init(&sem_entrygate, 0, 2);
    sem_init(&sem_exitgate, 0, 2);
    sem_init(&sem_globalupdate, 0, 1);

    printf("Creating %d car threads.\n", cars);

    pthread_t carthreads[cars];

    for(int i = 0; i < cars; i++)
    {
        pthread_create(&carthreads[i], NULL, car_thread, (void *)&i);
    }

    for(int i = 0; i < cars; i++)
    {
        pthread_join(carthreads[i], NULL);
    }

    printf("PROGRAM COMPLETE\n");
    exit(0);
}