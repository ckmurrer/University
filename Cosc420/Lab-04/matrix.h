#ifndef MATRIX_H
#define MATRIX_H

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<mpi.h>
#include<math.h>

#define INDEX(A,i,j) A.cols*i+j
#define ACCESS(A,i,j) A.data[INDEX(A,i,j)]

typedef struct matrix{
    int rows;
    int cols;
    double* data;
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
   	double innerProduct(matrix* A,matrix* B, MPI_Comm world,int wSize, int rank);
// printMatrix
	void printMatrix(matrix* A);
// subtraction
	matrix  matrixSubtraction(matrix* A,matrix* B, MPI_Comm world,int wSize, int rank);
// transpose
	matrix matrixTranspose(matrix* A);
// gauss jordan
	double* gaussJordan(matrix* A, matrix* B, MPI_Comm world, int wSize, int rank);
// copy matrix
	void copyMatrix(matrix* A, matrix* B);
// normalization
	double normalize(matrix* A, MPI_Comm world, int wSize, int rank);
// eigen vector
	double* eigenVector(char* fileName, MPI_Comm world, int dimensions, int wSize, int rank);
// eigen vector file
	double* eigenVectorFile(char* fileName, MPI_Comm world, int dimensions, int wSize, int rank);
#endif
