#include <iostream>
#include <stdio.h>
#include <string.h>
#include "mpi.h" //message passing interface
using namespace std;

//New compile and run commands for MPI!
// mpicxx -o blah file.cpp
// mpirun -q -np 32 blah

int main (int argc, char * argv[]) {

	int my_rank;			// my CPU number for this process
	int p;					// number of CPUs that we have
	int source;				// rank of the sender
	int dest;				// rank of destination
	int tag = 0;			// message number
	char message1[100];		// message itself
    char message2[100];		// message itself
	MPI_Status status;		// return status for receive
	
	//Start MPI
	MPI_Init(&argc, &argv);
	//Find out my rank
	MPI_Comm_rank(MPI_COMM_WORLD, &my_rank);	
	//Find out the number of processes
	MPI_Comm_size(MPI_COMM_WORLD, &p);
	
	//PROGRAM
	char * ring1 = message1;
    char * ring2 = message2;
	sprintf(ring1, "Frodo is a");
	sprintf(ring2, "Dumb Dumb");
	
	
	if(my_rank == 0) {          //first ring starts
		MPI_Send(ring1, strlen(ring1)+1, MPI_CHAR, 2, tag, MPI_COMM_WORLD);
		MPI_Recv(ring1, 100, MPI_CHAR, p-2 + (p%2), tag, MPI_COMM_WORLD, &status);
		cout << "The first ring has completed its cycle:" <<endl;
		cout << ring1 << endl;
	} else if(my_rank == 1) {   //second ring starts
        MPI_Send(ring2, strlen(ring1)+1, MPI_CHAR, 3, tag, MPI_COMM_WORLD);
		MPI_Recv(ring2, 100, MPI_CHAR, p-1 - (p%2), tag, MPI_COMM_WORLD, &status);
		cout << "The second ring has completed its cycle:" <<endl;
		cout << ring2 << endl;
    } else if(my_rank%2==0){    //first ring cycle
		MPI_Recv(ring1, 100, MPI_CHAR, my_rank - 2, tag, MPI_COMM_WORLD, &status);
		MPI_Send(ring1, strlen(ring1)+1, MPI_CHAR, (my_rank + 2) % (p + (p%2)), tag, MPI_COMM_WORLD);
	} else {                    //second ring cycle
        MPI_Recv(ring2, 100, MPI_CHAR, my_rank - 2, tag, MPI_COMM_WORLD, &status);
		MPI_Send(ring2, strlen(ring2)+1, MPI_CHAR, (my_rank + 2) % (p - (p%2)), tag, MPI_COMM_WORLD);
    }
	
	
	//Shut down MPI
	MPI_Finalize();
	return 0;
}