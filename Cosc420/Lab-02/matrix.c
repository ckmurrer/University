#include "matrix.h"

void initMatrix(matrix* A, int rows, int cols){
    srand(time(0));
	A->rows = rows;
    A->cols = cols;
    A->data = malloc(A->rows*A->cols*sizeof(int));

    int i,j;
    for(i=0; i<rows; i++){
        for (j=0; j < cols; j++){
            ACCESS(A,i,j) = rand()%10+1;
        }
    }
}

void printMatrix(matrix* A){
    int i,j;
    for(i=0; i<A->rows;i++){
        for(j=0; j<A->cols;j++){
            printf("%.02d | ",ACCESS(A,i,j));
        }
        printf("\n");
    }
}

void matrixAddition(){

}

void matrixSubraction(){

}
