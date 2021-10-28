#ifndef MATRIX_H
#define MATRIX_H

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<mpi.h>

#define INDEX(A,i,j) A.cols*i+j
#define ACCESS(A,i,j) A.data[INDEX(A,i,j)]

typedef struct matrix{
    int rows;
    int cols;
    int* data;
}matrix;

// initMatrix
	void initMatrix(matrix* A, int rows, int cols);
// matrix random population
	void populateMatrix(matrix* A, int rows, int cols);
// multiplication
	matrix matrixMutiplication(matrix* A,matrix* B, MPI_Comm world,int wSize, int rank);
// addition
	matrix matrixAddition(matrix* A,matrix* B, MPI_Comm world,int wSize, int rank);
// innerproduct
   	int innerProduct(matrix* A,matrix* B, MPI_Comm world,int wSize, int rank);
// printMatrix
	void printMatrix(matrix* A);
// subtraction
	matrix  matrixSubtraction(matrix* A,matrix* B, MPI_Comm world,int wSize, int rank);
// transpose
	matrix matrixTranspose(matrix* A);
// gauss jordan
	
#endif
