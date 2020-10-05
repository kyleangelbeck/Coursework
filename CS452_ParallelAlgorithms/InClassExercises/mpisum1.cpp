#include <iostream>
#include <stdio.h>
#include <string.h>
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
    
    /*
	int sum = 0;
    for(int i=0; i<300000, i++) {
        sum += i;
    }
    cout << sum << endl;
    */

    //STEPS FOR SOLVING AN EMBARRASSINGLY PARALLEL PROBLEM
    //1. Know the problem
	int n = 300000;
	long sum = 0;
    
	//2. Break the problem into pieces
	int local_start = n/p*my_rank;
	
	//3. Each process does its local work
	long local_sum = 0;
	for(int i=local_start; i<local_start+n/p; i++) {
		local_sum += i;
	}
	
    //4. Combine the local answers back together
	//The processor that is "in charge" is called the overseer
	//By convention, the overseer is usually process 0
	if(my_rank!=0) {
		MPI_Send(&local_sum, 1, MPI_LONG, 0, tag, MPI_COMM_WORLD);
	} else {
		sum = local_sum;
		long temp;
		for(int i=1; i<p; i++) {
			MPI_Recv(&temp, 1, MPI_LONG, MPI_ANY_SOURCE, tag, MPI_COMM_WORLD, &status);
			sum += temp;
		}
		cout<<sum<<endl;
	}


    // Shut down MPI
	MPI_Finalize();

	return 0;
}