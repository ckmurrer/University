#ifndef MATRIX_H
#define MATRIX_H

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<mpi.h>

#define INDEX(A,i,j) j+A->cols*i
#define ACCESS(A,i,j) A->data[INDEX(A,i,j)]

typedef struct matrix{
    int rows;
    int cols;
    int* data;
}matrix;

// initMatrix
	void initMatrix(matrix*, int, int);
// multiplication
	matrix matrixMutiplication(matrix*,matrix*, MPI_Comm);
// addition
	matrix matrixAddition(matrix*, matrix*, MPI_Comm);
// innerproduct
   	matrix innerProduct(matrix*, matrix*, MPI_Comm);
// printMatrix
	void printMatrix(matrix*);
// subtraction
	matrix  matrixSubtraction(matrix*, matrix*, MPI_Comm);
// transpose
	matrix matrixTranspose(matrix*,MPI_Comm);
#endif
