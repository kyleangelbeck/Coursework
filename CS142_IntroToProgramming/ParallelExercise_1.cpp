#include <iostream>
#include <cstdio> //required for sprintf function
#include <string>
#include "mpi.h" // message passing interface
using namespace std;
int main (int argc, char * argv[]) {
int x, y, z,i;
int my_rank; // my CPU number for this process
int p; // number of CPUs that we have
int source; // rank of the sender
int dest; // rank of destination
int tag = 0; // message number
char message[100]; // message itself
MPI_Status status; // return status for receive
// Start MPI
MPI_Init(&argc, &argv);
// Find out my rank!
MPI_Comm_rank(MPI_COMM_WORLD, &my_rank);
// Find out the number of processes!
MPI_Comm_size(MPI_COMM_WORLD, &p);
// THE REAL PROGRAM IS HERE
x=100; y=200; z=300;
if (my_rank==0){
for ( i=1; i<p; i++)
{
dest=i; tag=i;
if (i%3==0) {
x=0; y=1;
MPI_Send(&x, 1, MPI_INT, dest, tag, MPI_COMM_WORLD);
}
else if (i%3==1) {
x=3; y=4;
MPI_Send(&z, 1, MPI_INT, dest, tag, MPI_COMM_WORLD);
}
else if (i%3==2){
x=6; y=7;
MPI_Send(&y, 1, MPI_INT, dest, tag, MPI_COMM_WORLD);
}
}
}
else {
MPI_Recv(&x, 1, MPI_INT, 0, MPI_ANY_TAG, MPI_COMM_WORLD, &status);
}
cout<<" x= "<<x<<" receiving by proc "<<my_rank<<endl;
// Shut down MPI
MPI_Finalize();
return 0;
}