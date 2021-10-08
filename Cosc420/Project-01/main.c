#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>
#include<mpi.h>

int main(int* argc, int** argv){
	MPI_init(NULL,NULL);
	
	

	MPI_Finalize();
	return(0);
}
