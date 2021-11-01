#include <stdio.h>
#include <mpi.h>

int main(int argc, char* argv[]){
	MPI_Init(NULL,NULL);
	MPI_Finalize();
	return 0;
}
