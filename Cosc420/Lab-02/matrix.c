#include "matrix.h"

void initMatrix(matrix* A, int rows, int cols){
	A->rows = rows;
    A->cols = cols;
    A->data = malloc(A->rows*A->cols*sizeof(int));
}

void populateMatrix(matrix* A, int rows, int cols){
    int i,j;
    for(i=0; i<rows; i++){
        for (j=0; j < cols; j++){
            ACCESS((*A),i,j) = rand()%100+1;
        }
    }
}

void printMatrix(matrix* A){
    int i,j;
    for(i=0; i<A->rows;i++){
        for(j=0; j<A->cols;j++){
           printf("%.02d | ",ACCESS((*A),i,j));
        }
        printf("\n");
    }
}

int* matrixAddition(matrix* A, matrix* B, MPI_Comm world, int wSize, int rank){
   if(A->cols!=B->cols){
       printf("Why are we here? Just to suffer?\nInvalid matrix dimensions btw.\n");
       return 0;
   }
    int* addTotal;
    int* temp;
    int matSize = A->rows*A->cols;
    int* sendCount = malloc(wSize*sizeof(int));
    int* displace = malloc(wSize*sizeof(int));
    int* recBufA = malloc(matSize*sizeof(int));
    int* recBufB = malloc(matSize*sizeof(int));
    int minSend = matSize/wSize;
    int i;
    for(i=0; i<wSize; i++){
        sendCount[i] = minSend;
        displace[i] = minSend*i;
    }
    for(i=0; i<matSize%wSize;i++){
        sendCount[i]++;
    }
    
    MPI_Scatterv(
        A->data,
        sendCount,
        displace,
        MPI_INT,
        recBufA,
        sendCount[rank],
        MPI_INT,
        0,
        world
    );
    MPI_Scatterv(
        B->data,
        sendCount,
        displace,
        MPI_INT,
        recBufB,
        sendCount[rank],
        MPI_INT,
        0,
        world
    );
    temp = malloc(matSize*sizeof(int));
    addTotal = malloc(matSize*sizeof(int)); // needs to be freed
    for(i=0; i<minSend; i++){
        temp[i] = recBufA[i]+recBufB[i];
    }
    MPI_Gatherv(
        temp,
        minSend,
        MPI_INT,
        addTotal,
        sendCount,
        displace,
        MPI_INT,
        0,
        world
    );
    free(temp);
    free(sendCount);
    free(displace);
    free(recBufA);
    free(recBufB);    
	return addTotal;
}

int* matrixSubtraction(matrix* A, matrix* B, MPI_Comm world, int wSize, int rank){
	int* subTotal;
	int* temp;
    int matSize = A->rows*A->cols;
    int* sendCount = malloc(wSize*sizeof(int));
    int* displace = malloc(wSize*sizeof(int));
    int* recBufA = malloc(matSize*sizeof(int));
    int* recBufB = malloc(matSize*sizeof(int));
    int minSend = matSize/wSize;
    int i;
    for(i=0; i<wSize; i++){
        sendCount[i] = minSend;
        displace[i] = minSend*i;
    }
    for(i=0; i<matSize%wSize;i++){
        sendCount[i]++;
    }
    
    MPI_Scatterv(
        A->data,
        sendCount,
        displace,
        MPI_INT,
        recBufA,
        sendCount[rank],
        MPI_INT,
        0,
        world
    );
    MPI_Scatterv(
        B->data,
        sendCount,
        displace,
        MPI_INT,
        recBufB,
        sendCount[rank],
        MPI_INT,
        0,
        world
    );
    temp = malloc(matSize*sizeof(int));
    subTotal = malloc(matSize*sizeof(int)); // needs to be freed
    for(i=0; i<minSend; i++){
        temp[i] = recBufA[i]-recBufB[i];
    }
    MPI_Gatherv(
        temp,
        minSend,
        MPI_INT,
        subTotal,
        sendCount,
        displace,
        MPI_INT,
        0,
        world
    );
    free(temp);
    free(sendCount);
    free(displace);
    free(recBufA);
    free(recBufB);  
	return subTotal;
}
// TODO
int* matrixMutiplication(matrix* A,matrix* B, MPI_Comm world,int wSize, int rank){
    int* multTotal;
   
    return multTotal;
}

// TODO
int innerProduct(matrix* A,matrix* B, MPI_Comm world,int wSize, int rank){
    int inProd = 0;

    return inProd;
}

// TODO
int* matrixTranspose(matrix* A){
    int* tPose;
  
    return tPose;
}
