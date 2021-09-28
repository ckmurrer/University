#ifndef MATRIX_H
#define MATRIX_H

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<mpi.h>

#define INDEX(A,i,j) j*A.cols+i
#define ACCESS(A,i,j) A.data[INDEX(A,i,j)]

typedef struct matrix{
    int rows;
    int cols;
    int* data;
}matrix;

// initMatrix
	void initMatrix(matrix*, int, int);
// matrix random population
	void populateMatrix(matrix*, int, int);
// multiplication
	int* matrixMutiplication(matrix*,matrix*, MPI_Comm,int, int);
// addition
	int* matrixAddition(matrix*,matrix*, MPI_Comm,int, int);
// innerproduct
   	int innerProduct(matrix*,matrix*, MPI_Comm,int, int);
// printMatrix
	void printMatrix(matrix*);
// subtraction
	int*  matrixSubtraction(matrix*,matrix*, MPI_Comm,int, int);
// transpose
	int* matrixTranspose(matrix*);
#endif
