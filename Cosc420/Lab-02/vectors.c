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

// variables that are to be used 
    int* vecOne = NULL;
    int* recOne = NULL;
    int* vecTwo = NULL;
    int* recTwo = NULL;
    int prod = 0;
    int prodResult = 0;
    int arrSize = 11/*rand()%1000000+1*/;
    int recSize = arrSize / wSize;
    recOne = malloc(recSize*sizeof(int));
    recTwo = malloc(recSize*sizeof(int));

// root node allocated size of vectors and populates them.
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

// scatter both the vectors populated by root node 0
    MPI_Scatter(
        vecOne,     //Vector one
        recSize,    //Size of amount of data being sent
        MPI_INT,    //Type of data being sent
        recOne,     //Receiving vector
        recSize,    //Size of receiving vector
        MPI_INT,    //Type of data being received
        0,          //Root Node
        world       //Comm
    );
    MPI_Scatter(
        vecTwo,     //Vector one
        recSize,    //Size of amount of data being sent
        MPI_INT,    //Type of data being sent
        recTwo,     //Receiving vector
        recSize,    //Size of receiving vector
        MPI_INT,    //Type of data being received
        0,          //Root Node
        world       //Comm
    );

    int k;
    for(k = 0; k<recSize;k++){
        printf("Rank: %d ----- %d ----- %d\n",rank,recOne[k],recTwo[k]);
    }

// takes inner product of two vectors
    int i;
    for(i=0; i<recSize;i++){
        prod += recOne[i] * recTwo[i];
    }
        printf("Rank: %d --- prod: %d\n",rank,prod);
    MPI_Reduce(
        &prod,
        &prodResult,
        1,
        MPI_INT,
        MPI_SUM,
        0,
        world
    );

// output of inner product total
    if(rank == 0){
        printf("The inner product result is: %d\n",prodResult);
    }
// clearing up memory and terminating program
    free(vecOne);
    free(vecTwo);
    free(recOne);
    free(recTwo);
	MPI_Finalize();
	return 0;
}
