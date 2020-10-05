#include<iostream>
#include<fstream>
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
    int * counts = new int[26]; //count of each letter
    int n = 50;                 //num of characters
    char * input = new char[n]; //input characters


    //Read in file

    ifstream inputFile;
    inputFile.open("input.txt");
    if (inputFile.is_open()) {
        int i=0;
        while (!inputFile.eof()) {
            inputFile >> input[i];
            i++;
        }
    }
    inputFile.close();


    //scatter
    int localn = n/p;
    char * localin = new char [localn];
    MPI_Scatter(input, localn, MPI_CHAR, localin, localn, MPI_CHAR, 0, MPI_COMM_WORLD);


    // 3) Do the Local Work
    int * localcounts = new int [26];

    //using ascii value
    for(int i=0; i<localn; i++) {
        localcounts[localin[i]-97]++;
        //cout<<localin[i]<<": "<<localin[i]-97<<endl;
    }

    // 4) Combine Results
    for(int i=0; i<26; i++) {
        MPI_Reduce(&localcounts[i], &counts[i], 1, MPI_INT, MPI_SUM, 0, MPI_COMM_WORLD);
    }

	//Print number of p's for example
    if(my_rank==0) cout<<"Number of p's: "<<counts[15]<<endl;
	



    delete [] counts;
    delete [] input;
    delete [] localcounts;
    delete [] localin;
    // Shut down MPI
	MPI_Finalize();

	return 0;
}