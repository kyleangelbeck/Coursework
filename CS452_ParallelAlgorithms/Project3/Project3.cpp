/*
Kyle Angelbeck, Nick Stitely, Lauren Marx
Parallel Algorithms Project 3: Parallel Mergesort
April 27, 2020
*/

#include <iostream>
#include <stdio.h>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include <string.h>
#include <algorithm>    //Sort()
#include <math.h>       //log()
#include "mpi.h" // message passing interface
using namespace std;

// New compile and run commands for MPI!
// mpicxx -o testing Project3Final.cpp
// mpirun -q -np 4 testing

void mergesort(int * a, int first, int last, int my_rank, int p);
void smerge(int * a, int first1, int last1, int first2, int last2);
int rank(int * a, int first, int last, int valToFind);
void pmerge(int * a, int first1, int last1, int first2, int last2, int my_rank, int p);

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
	

	//Create and broadcast size of array
    int n=32;
    if(my_rank == 0){
        cout<<"Input the size of the array"<<endl;
        cin>>n;
    }
    MPI_Bcast(&n, 1, MPI_INT, 0, MPI_COMM_WORLD);
    

    //Create and broadcast array
    int * array = new int[n];
    if(my_rank == 0) {
        srand(time(NULL));
        cout<<"\nUnsorted Array From Proc 0: \n";
        for(int i=0; i<n; i++) {
            array[i]=rand()%1000000;
            //array[i]=rand()%100;
            cout<<array[i]<<", ";
        }
        cout<<endl<<endl;
    }
    MPI_Bcast(array, n, MPI_INT, 0, MPI_COMM_WORLD);

    mergesort(array,0,n-1,my_rank,p);

    if(my_rank==0) {
        cout<<"FINAL ARRAY:\n";
        for(int i=0; i<n; i++) {
            cout<<array[i]<<", ";
        }
        cout<<endl;
    }

	// Shut down MPI
	MPI_Finalize();
	return 0;
}


int rank(int * a, int first, int last, int valToFind) {
    int middle  = (first+last)/2;
    while(first<=last){
        if(a[middle] == valToFind)
            return middle+1;
        else if(a[middle] < valToFind)
            first = middle + 1;
        else
            last = middle-1;
        middle = (first+last)/2;
    }

    if(valToFind > a[middle])
        return middle+1;
    return middle+1;
}


void smerge(int * a, int first1, int last1, int first2, int last2) {
	int i, j, k;
	int n1 = last1 - first1 + 1;    // size of first array
	int n2 = last2 - first2 + 1;    // size of second array
	int L[n1], R[n2];               // temp arrays to hold both arrays
	
    //fill temp arrays
	for (i = 0; i < n1; i++)
		L[i] = a[first1 + i];
	for (j = 0; j < n2; j++)
		R[j] = a[first2 + j];
	
    //merge into first array
	i = 0;
	j = 0;
	k = first1;
	while(i < n1 && j < n2 && k<=last1) {
		if (L[i] <= R[j]) {
			a[k] = L[i];
			i++;
		} else {
			a[k] = R[j];
			j++;
		}
		k++;
	}
    while(i < n1 && k<=last1) {
		a[k] = L[i];
		i++;
		k++;
	}
	while(j < n2 && k<=last1) {
		a[k] = R[j];
		j++;
		k++;
	}

    //merge into second array
    k = first2;
	while(i < n1 && j < n2) {
		if (L[i] <= R[j]) {
			a[k] = L[i];
			i++;
		} else {
			a[k] = R[j];
			j++;
		}
		k++;
	}
	while(i < n1) {
		a[k] = L[i];
		i++;
		k++;
	}
	while(j < n2) {
		a[k] = R[j];
		j++;
		k++;
	}
}

// mergesort function
void mergesort(int * a, int first, int last, int my_rank, int p) {
	if(first < last) {
        //base case
        if(last-first<1) return;
        if(last-first==1){
            if(a[last]<a[first]) {
                int temp = a[last];
                a[last] = a[first];
                a[first] = temp;
            }
            return;
        }

		int first1 = first;
		int last1 = first1 + (last - first1) / 2;
		int first2 = last1 + 1;
		int last2 = last;
		mergesort(a, first1, last1, my_rank, p);
		mergesort (a, first2, last2, my_rank, p);
		pmerge(a, first1, last1, first2, last2, my_rank, p);
	}
}

void pmerge(int * a, int first1, int last1, int first2, int last2, int my_rank, int p) {
    int n = last1-first1+1;                         //length of first input array
    int m = last2-first2+1;                         //length of second input array
    int SRANKAlength = n/log2(m);                   //length of SRANKA (Also number of arrows from A to B)
    int SRANKBlength = m/log2(n);                   //length of SRANKB (Also number of arrows from B to A)
    int * SRANKA = new int[SRANKAlength]();         //local SRANKA
    int * SRANKB = new int[SRANKBlength]();         //local SRANKB
    int * SRANKANEW = new int[SRANKAlength]();      //shared SRANKA
    int * SRANKBNEW = new int[SRANKBlength]();      //shared SRANKB
    int * WIN = new int[n+m]();                     //local win
    int * WINWIN = new int[n+m]();                  //global win
    //2 * total number of arrows
    int SmergeSize = SRANKAlength+SRANKBlength;     //size of shape helpers
    int ShapeSize = 2*(SRANKAlength+SRANKBlength);  //size of shapes
    int * SmergeA = new int[SmergeSize]();          //ShapeA helper 
    int * SmergeB = new int[SmergeSize]();          //ShapeB helper
    int * ShapeA = new int[ShapeSize]();            //indices for the top half of the shapes
    int * ShapeB = new int[ShapeSize]();            //indices for the bottom half of the shapes

    //print unsorted starting array.
    /*
    if(my_rank==0) {
        for(int i=first1; i<=last2; i++)
            cout<<a[i]<<", ";
        cout<<endl;
    }
    */

    //fill SRANKA and SRANKB
    for(int i=my_rank; i<SRANKAlength; i+=p) {
        SRANKA[i] = rank(a,first2,last2,a[i*int(log2(m))+first1]);
    }
    for(int i=my_rank; i<SRANKBlength; i+=p) {
        SRANKB[i] = rank(a,first1,last1,a[i*int(log2(n))+first2]);
    }

    //Reduces local arrays SRANKA and SRANKB to global arrays SRANKANEW and SRANKBNEW
    MPI_Allreduce(SRANKA, SRANKANEW, SRANKAlength, MPI_INT, MPI_SUM, MPI_COMM_WORLD);
    MPI_Allreduce(SRANKB, SRANKBNEW, SRANKBlength, MPI_INT, MPI_SUM, MPI_COMM_WORLD);
    
    //Fill Smerge A
    for(int i=0; i<SRANKAlength; i++) {
        SmergeA[i] = first1 + (i * int(log2(m)));
        SmergeA[i+SRANKAlength] = SRANKBNEW[i];
    }
    smerge(SmergeA,0,SRANKAlength-1,SRANKAlength,SmergeSize-1);

    //Fill Smerge B
    for(int i=0; i<SRANKAlength; i++) {
        SmergeB[i] = first2 + (i * int(log2(m)));
        SmergeB[i+SRANKAlength] = SRANKANEW[i];
    }
    smerge(SmergeB,0,SRANKAlength-1,SRANKAlength,SmergeSize-1);

    //Fill ShapeA
    for(int i=1; i<SmergeSize; i++) {
        ShapeA[(2*i)-1] = SmergeA[i] - 1;
        ShapeA[2*i] = SmergeA[i];
        ShapeB[(2*i)-1] = SmergeB[i] - 1;
        ShapeB[2*i] = SmergeB[i];
    }
    ShapeA[0] = first1;             //Always starts at the beginning of the array
    ShapeA[ShapeSize-1] = last1;    //Always ends at the end of the array
    ShapeB[0] = first2;             //Always starts at the beginning of the array
    ShapeB[ShapeSize-1] = last2;    //Always ends at the end of the array

    //SMerge Shapes and put them in WIN
    for(int i=2*my_rank; i<ShapeSize; i+=2*p) {
        //smerge shape
        smerge(a, ShapeA[i], ShapeA[i+1], ShapeB[i], ShapeB[i+1]);

        //Put first half of smerged shape into local WIN
        int temp = ShapeA[i]+rank(a,first2,last2,a[ShapeA[i]])-last1-1-first1;
        for(int j=ShapeA[i]; j<=ShapeA[i+1]; j++) {
            WIN[temp++]=a[j];
        }
        //put second half of smerged shape into local WIN
        temp = ShapeB[i]+rank(a,first1,last1,a[ShapeB[i]])-last1-1-first1;
        for(int j=ShapeB[i]; j<=ShapeB[i+1]; j++) {
            WIN[temp++]=a[j];
        }
    }
    //reduce local WINs into global WINWIN.
    MPI_Allreduce(WIN, WINWIN, n+m, MPI_INT, MPI_SUM, MPI_COMM_WORLD);
    MPI_Allreduce(WIN, &a[first1], n+m, MPI_INT, MPI_SUM, MPI_COMM_WORLD);

    //Output array
    /*
    if(my_rank==0){
        cout<<"WIN:";
        for(int i = 0; i<n+m; i++){
            cout<<WINWIN[i]<<", ";
        }
        cout<<endl<<endl;
    }
    */
}