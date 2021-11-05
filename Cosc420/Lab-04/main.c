#include <stdio.h>
#include <mpi.h>

int main(int argc, char* argv[]){
	MPI_Init(NULL,NULL);
	MPI_Comm world = MPI_COMM_WORLD;
	int wSize, rank;
	MPI_Comm_rank(world,&rank);
	MPI_Comm_size(world,&wSize);

	MPI_Finalize();
	return 0;
}
