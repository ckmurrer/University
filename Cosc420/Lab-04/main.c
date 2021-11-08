#include <stdio.h>
#include "matrix.h"
#include <mpi.h>


void testFile(int dimension, MPI_Comm world, int wSize, int rank){
	matrix* temp;
	initMatrix(temp,dimension,dimension);
	int vector[wSize];
	int displacement[wSize];
	int size = dimension*dimension;
	int i;
	for(i=0; i<wSize; i++){
		vector[i] = size/wSize;
	}
	for(i=0; i<size%wSize; i++){
		vector[i]+=1;
	}
	populateMatrix(temp,dimension,dimension);
	int len = 0;
	for(i=0; i< wSize; i++){
		if(i==0){
			displacement[i]=0;
			len = vector[i];
			continue;
		}
		displacement[i] = displacement[i-1]+len;
		len = vector[i];
	}
	MPI_File file;
	MPI_File_open(
		world,
		"plsWorkThisTime",
		MPI_MODE_CREATE | MPI_MODE_WRONLY,
		MPI_INFO_NULL,
		&file
	);

	MPI_Offset offset = displacement[rank]*sizeof(double);
	MPI_File_write_at(
		file,
		offset,
		temp->data,
		vector[rank],
		MPI_DOUBLE,
		MPI_STATUS_IGNORE
	);
	MPI_File_close(&file);
	free(temp->data);
}

int main(int argc, char* argv[]){
	srand(time(NULL));

	MPI_Init(NULL,NULL);
	MPI_Comm world = MPI_COMM_WORLD;
	int wSize, rank;
	MPI_Comm_rank(world,&rank);
	MPI_Comm_size(world,&wSize);
	int size = 5;
	int i;
	if(rank == 0){
		testFile(size, world,wSize,rank);
	}
	matrix plsWork;
	plsWork.rows = size;
	plsWork.cols = 1;
	plsWork.data = eigenVector("plsWorkThisTime",world,size,wSize,rank);
	


	MPI_Finalize();
	return 0;
}
