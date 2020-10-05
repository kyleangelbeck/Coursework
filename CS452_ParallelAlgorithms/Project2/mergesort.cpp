#include <iostream>
#include <stdio.h>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
using namespace std;

void merge(int * a, int first, int last, int middle) {
    //cout<<"merge called\n";
    int * b = new int[last-first+1];
    int firstcounter = first;
    int lastcounter = middle+1;

    for(int i=0; i<last-first+1; i++){

        if(lastcounter > last || (firstcounter <= middle && a[firstcounter]<=a[lastcounter]))
            b[i] = a[firstcounter++];
        else
            b[i] = a[lastcounter++];
    }
    //copy newarray into a
    for(int i=0; i<last-first+1; i++) {
        a[i+first] = b[i];
    }
    //cout<<"merge completed\n";
}

void mergesort (int * a, int first, int last) {
    //cout<<"mergesort called\n";
    if(last-first<=0) return;
    if(last-first==1) {
        if(a[first]>a[last]) {
            int temp = a[first];
            a[first] = a[last];
            a[last] = temp;
        }
        return;
    }

    mergesort(a, first, (first+last)/2);
    mergesort(a, (first+last)/2 + 1, last);

    merge(a, first, last, (first+last)/2);
}

int main() {
    //create array
    int n;
    cout<<"Input the size of the array"<<endl;
    cin>>n;
    int * array = new int[n]; //count of each letter
    int * b;

    //randomly fill (and output) array
    srand(71911);
    cout<<"Unsorted Array: ";
    for(int i=0; i<n; i++) {
        array[i]=rand()%1000000;
        cout<<array[i]<<", ";
    }
    cout<<"\narray made\n";

    mergesort(array, 0, n-1);

    //output unsorted array
    cout<<"Sorted Array: ";
    for(int i=0; i<n; i++)
        cout<<array[i]<<", ";
    cout<<endl;
}