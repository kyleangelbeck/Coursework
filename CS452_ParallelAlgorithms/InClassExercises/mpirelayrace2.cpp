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
	char message[100];		// message itself
	MPI_Status status;		// return status for receive
	
	//Start MPI
	MPI_Init(&argc, &argv);
	//Find out my rank
	MPI_Comm_rank(MPI_COMM_WORLD, &my_rank);	
	//Find out the number of processes
	MPI_Comm_size(MPI_COMM_WORLD, &p);
	
	//PROGRAM
	char * baton = message;
	sprintf(baton, "Sent list: ");
	sprintf(baton + strlen(baton), "%d ", my_rank);
	
	

	if(my_rank == 0) {
		cout << "Runner Zero Has Began Running" << endl;
		MPI_Send(baton, strlen(baton)+1, MPI_CHAR, 1, tag, MPI_COMM_WORLD);
		MPI_Recv(baton, 100, MPI_CHAR, p, tag, MPI_COMM_WORLD, &status);
		cout << "Race Finished" <<endl;
		cout << baton << endl;
	} else {
		MPI_Recv(baton, 100, MPI_CHAR, my_rank - 1, tag, MPI_COMM_WORLD, &status);
		sprintf(baton + strlen(baton), "%d ", my_rank);
		cout << "Runner " << my_rank << " Has Began Running" << endl;
		MPI_Send(baton, strlen(baton)+1, MPI_CHAR, (my_rank + 1) % p, tag, MPI_COMM_WORLD);
		cout << baton << endl;
	}
	
	
	//Shut down MPI
	MPI_Finalize();
	return 0;
}