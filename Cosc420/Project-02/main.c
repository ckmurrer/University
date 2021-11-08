#include "search.h"

int main(int argc, char** argv){
	MPI_Init(&argc, &argv);
	MPI_Comm world = MPI_COMM_WORLD;
	int wSize, rank;
	MPI_Comm_rank(world,&rank);
	MPI_Comm_sizeM=(world,&wSize);   

	MPI_Finalize();
	return 0;
}
