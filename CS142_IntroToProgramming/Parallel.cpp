//Kyle Angelbeck
//CS142-02
#include <iostream>
#include <cstdio>
#include <string>
#include "mpi.h"
using namespace std;
int main (int argc, char * argv[]) {
	int even, odd;
	int my_rank;
	int p;
	int source;
	int dest;
	int tag = 0;
	char message[100];
	MPI_Status status;
	MPI_Init(&argc, &argv);
	MPI_Comm_rank(MPI_COMM_WORLD, &my_rank);
	MPI_Comm_size(MPI_COMM_WORLD, &p);
	
	sprintf(message, "Message of death from process %d", my_rank);
	if(p%2==0) {
		even = p-2;
		odd = p-1;
	} else if(p%2==1) {
		even = p-1;
		odd = p-2;
	}
	if(my_rank == 0) {
		MPI_Send(message,  strlen(message)+1, MPI_CHAR, 2, tag,  MPI_COMM_WORLD);
		MPI_Recv(message, 100, MPI_CHAR, even, tag, MPI_COMM_WORLD, &status);
	} else if(my_rank == 1) {
		MPI_Send(message,  strlen(message)+1, MPI_CHAR, odd, tag,  MPI_COMM_WORLD);
		MPI_Recv(message, 100, MPI_CHAR, 3, tag, MPI_COMM_WORLD, &status);
	} else if(my_rank == odd) {
		MPI_Send(message,  strlen(message)+1, MPI_CHAR, my_rank-2, tag,  MPI_COMM_WORLD);
		MPI_Recv(message, 100, MPI_CHAR, 1, tag, MPI_COMM_WORLD, &status); 
	} else if(my_rank == even) {
		MPI_Send(message,  strlen(message)+1, MPI_CHAR, 0, tag,  MPI_COMM_WORLD);
		MPI_Recv(message, 100, MPI_CHAR, my_rank-2, tag, MPI_COMM_WORLD, &status);
	} else if(my_rank%2==0) {
		MPI_Send(message,  strlen(message)+1, MPI_CHAR, my_rank+2, tag,  MPI_COMM_WORLD); 
		MPI_Recv(message, 100, MPI_CHAR, my_rank-2, tag, MPI_COMM_WORLD, &status);
	} else if(my_rank%2==1){
		MPI_Send(message,  strlen(message)+1, MPI_CHAR, my_rank-2, tag,  MPI_COMM_WORLD);
		MPI_Recv(message, 100, MPI_CHAR, my_rank+2, tag, MPI_COMM_WORLD, &status);
	}
	printf("%s printed by process %d\n", message, my_rank);
	MPI_Finalize();
	return 0;
} /*
Message of death from process 0 printed by process 2
Message of death from process 2 printed by process 4
Message of death from process 3 printed by process 1
Message of death from process 5 printed by process 3
Message of death from process 7 printed by process 5
Message of death from process 8 printed by process 0
Message of death from process 4 printed by process 6
Message of death from process 9 printed by process 7
Message of death from process 6 printed by process 8
Message of death from process 1 printed by process 9 */