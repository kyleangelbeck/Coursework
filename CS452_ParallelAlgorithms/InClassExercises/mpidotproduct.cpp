#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "mpi.h" // message passing interface
using namespace std;

// New compile and run commands for MPI!
// mpicxx -o blah file.cpp
// mpirun -q -np 32 blah

int main (int argc, char * argv[]) {

	int my_rank;			// my CPU number for this process
	int p;					// number of CPUs that we have
	int source;				// rank of the sender
	int dest;				// rank of destination
	int tag = 0;			// message number
	char message[100];		// message itself
	MPI_Status status;		// return status for receive
	
	// Start MPI
	MPI_Init(&argc, &argv);
	
	// Find out my rank!
	MPI_Comm_rank(MPI_COMM_WORLD, &my_rank);
	
	// Find out the number of processes!
	MPI_Comm_size(MPI_COMM_WORLD, &p);
	
	// THE REAL PROGRAM IS HERE

    // 1) Know the Problem
    srand(1241);
    int n = 300000;
    int * a = new int[n];
    int * b = new int[n];
    long int dotproduct = 0;

    if(my_rank == 0) {
        for(int i=0; i<n; i++) {
            a[i] = rand()%8;
            b[i] = rand()%8;
        }
    }

    // 2) Divide the Problem
    int localn = n/p;
    int * locala = new int [localn];
    int * localb = new int [localn];

    /*MPI_SCATTER(Origin Array, Size data sent, Type of data sent,
                  Where to put the data, size of input data, type of input data, process that has big array, MPI_COMM_WORLD)*/
    MPI_Scatter(&a[0], localn, MPI_INT, locala, localn, MPI_INT, 0, MPI_COMM_WORLD);
    MPI_Scatter(&b[0], localn, MPI_INT, localb, localn, MPI_INT, 0, MPI_COMM_WORLD);


    // 3) Do the Local Work
    long int localdot = 0;
    for (int i=0; i<localn; i++) {
        localdot += locala[i] * localb[i];
    }

    // 4) Combine Results
    if(my_rank != 0) {
        MPI_Send(&localdot, 1, MPI_LONG, 0, tag, MPI_COMM_WORLD);
    } else {
        dotproduct = localdot;
        long int temp = 0;
        for(int i=1; i<p; i++) {
            MPI_Recv(&temp, 1, MPI_LONG, MPI_ANY_SOURCE, tag, MPI_COMM_WORLD, &status);
            dotproduct += temp;
        }
        cout << dotproduct << endl;
        //check with non parallel
        dotproduct = 0;
        for(int i=0; i<n; i++) {
            dotproduct += a[i] * b[i];
        }
        cout << dotproduct << endl;
    }




    delete [] a;
    delete [] b;
    delete [] locala;
    delete [] localb;
    // Shut down MPI
	MPI_Finalize();

	return 0;
}