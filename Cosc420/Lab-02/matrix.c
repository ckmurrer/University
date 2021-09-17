#include<stdio.h>
#include<mpi.h>

#define INDEX(n,m,i,j) m*i + j

int main(int argc, char** argv){
	

	MPI_Init(&argc,&argv);
	MPI_Comm world = MPI_COMM_WORLD;
	
	int* A = malloc(n*m*sizeof(int));
	int i,j;
	for(i=0; i<n; i++){
		for(j=0; j<m; j++){
			A[INDEX(n,m,i,j)] = rand();
		}
	}
	
	free(A);
	MPI_Finalize();
	return 0;
}
