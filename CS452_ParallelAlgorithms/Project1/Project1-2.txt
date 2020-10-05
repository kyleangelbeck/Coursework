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
    int min, max;
    double avg;

    //fill arrays
    srand(71911);
    int n = 100;
    int * a = new int[n];

    if(my_rank == 0) {
        for(int i=0; i<n; i++) {
            a[i] = rand()%300;
            //cout<<a[i]<<", ";
        }
        //cout<<endl;
    }

    //scatter
    int localn = n/p;
    int * locala = new int [localn];
    MPI_Scatter(a, localn, MPI_INT, locala, localn, MPI_INT, 0, MPI_COMM_WORLD);


    // 3) Do the Local Work
    int tempmin = locala[0];
    for (int i=1; i<localn; i++) {
        if(locala[i]<tempmin) tempmin = locala[i];
    }

    int tempmax = locala[0];
    for (int i=1; i<localn; i++) {
        if(locala[i]>tempmin) tempmax = locala[i];
    }

    double tempavg = 0.0;
    for (int i=0; i<localn; i++) {
        tempavg += locala[i];
    }
    tempavg /= localn;

    // 4) Combine Results
    MPI_Reduce(&tempmin, &min, 1, MPI_INT, MPI_MIN, 0, MPI_COMM_WORLD);
    MPI_Reduce(&tempmax, &max, 1, MPI_INT, MPI_MAX, 0, MPI_COMM_WORLD);
    MPI_Reduce(&tempavg, &avg, 1, MPI_DOUBLE, MPI_SUM, 0, MPI_COMM_WORLD);
    avg /= p;

    if(my_rank==0) cout<<"Minimum: "<<min<<", Maximum: "<<max<<", Average: "<<avg<<endl;



    delete [] a;
    delete [] locala;
    // Shut down MPI
	MPI_Finalize();

	return 0;
}