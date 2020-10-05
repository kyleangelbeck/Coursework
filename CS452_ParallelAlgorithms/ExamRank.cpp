#include <iostream>
#include <stdio.h>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include <string.h>
#include <algorithm>    //Sort()
#include <math.h>       //log()
using namespace std;

int rank(int * a, int first, int last, int valToFind);

int main () {
    int n=32;                   //array size
    int * array = new int[n];   //array
    int randVals = 10;

    //fill array
    srand(71911);
    cout<<"Sorted Array\n";
    for(int i=0; i<n; i++) {
        array[i]=rand()%randVals;
    }
    sort(array,array+n);
    for(int i=0; i<n; i++) {
        cout<<array[i]<<", ";
    }
    cout<<endl<<log2(n)<<endl;

    //output rank
    for(int i=0; i<randVals; i++) {
        cout<<endl<<"Rank of "<<i<<": "<<rank(array,0,n-1,i)<<endl;
    }

	return 0;
}


int rank(int * a, int first, int last, int valToFind) {
    int middle  = (first+last)/2;
    int i=0;
    while(first<=last){
        if(valToFind < a[middle])
            last = middle-1;
        else if(valToFind >= a[middle])
            first = middle + 1;
        middle = (first+last)/2;
        i++;
    }
    cout<<endl<<"Took "<<i<<" iterations to find value "<<valToFind;
    return middle+1;
}