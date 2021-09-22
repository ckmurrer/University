#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<mpi.h>

int main(int argc, char** argv){
	MPI_Init(&argc,&argv);
// gets the world world size and the rank	
    int wSize, rank;
    MPI_Comm world = MPI_COMM_WORLD;
    MPI_Comm_rank(world, &rank);
    MPI_Comm_size(world, &wSize);

    int* vecOne = NULL;
    int* recOne = NULL;
    int* vecTwo;
    int* recTwo;
    int arrSize = 11/*rand()%1000000+1*/;
    //int* prodResult;

    if(rank == 0){
        srand(time(0));
        vecOne = malloc(wSize*arrSize*sizeof(int));
        vecTwo = malloc(wSize*arrSize*sizeof(int));
        
        int i;
        for(i=0; i<arrSize*wSize;i++){
            vecOne[i] = rand()%100+1;
            vecTwo[i] = rand()%100+1;
        }
    }

    int recSize = arrSize / wSize;
    recOne = malloc(recSize*sizeof(int));
    recTwo = malloc(recSize*sizeof(int));

    MPI_Scatter(
        vecOne,
        recSize,
        MPI_INT,
        recOne,
        recSize,
        MPI_INT, 
        0, 
        world
    );
    MPI_Scatter(
        vecTwo,
        recSize,
        MPI_INT,
        recTwo,
        recSize,
        MPI_INT,
        0,
        world
    );

    int i;
    for(i=0; i<recSize; i++){
        printf("Rank: %d --- Element: %d is |%d |---| %d|.\n",rank,i,recOne[i],recTwo[i]);
    }
/*
	int n,m;
	int* A = malloc(n*m*sizeof(int));
	int i,j;
	for(i=0; i<n; i++){
		for(j=0; j<m; j++){
			A[INDEX(n,m,i,j)] = rand();
		}
	}
	
	free(A);
*/
// clearing up memory and terminating program
    free(vecOne);
    free(vecTwo);
    free(recOne);
    free(recTwo);
	MPI_Finalize();
	return 0;
}
