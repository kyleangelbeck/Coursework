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

    //Know the Problem
    srand(1241);
    int n = 9;
    int * a = new int[n];
    long *psum = new long[n];

    if(my_rank==0) {
        for(int i=0; i<n; i++) {
            a[i] = rand() % 8;
        }
    }

    //Divide the Problem
    int * locala = new int[n/p];
    long * localpsum = new long[n/p];

    MPI_Scatter(&a[0], n/p, MPI_INT, locala, n/p, MPI_INT, 0, MPI_COMM_WORLD);

    //Do the local work
    localpsum[0] = locala[0];
    for(int i=1; i<n/p; i++) {
        localpsum[i] = locala[i] + localpsum[i-1];
    }

    //Send last partial prefix sum answer to all later processors
    for (int i=my_rank+1; i<p; i++) {
        MPI_Send(&localpsum[n/p-1], 1, MPI_LONG, i, tag, MPI_COMM_WORLD);
    }

    //recieve answers from all previous processors
    long local_additive = 0;
    long temp;
    for(int i=0; i<my_rank; i++) {
        MPI_Recv(&temp, 1, MPI_LONG, MPI_ANY_SOURCE, MPI_COMM_WORLD, &status);
        local_additive += temp;
    }
    
    //add local additive to localpsum
    for(int i=0; i<n/p; i++) {
        localpsum[i] += local_additive;
    }

    //Collect back together
    MPI_Gather(localpsum, n/p, MPI_LONG, psum, n/p, MPI_LONG, 0, MPI_COMM_WORLD);

    //print out array 
    if(my_rank==0) {
        for(int i=0; i<p; i++) {
            cout<<psum[i]<<" ";
        }
        cout<<endl;
    }


    delete [] a;
    delete [] psum;
    delete [] locala;
    delete [] localpsum;
    // Shut down MPI
	MPI_Finalize();

	return 0;
}