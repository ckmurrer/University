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
	void matrixMutiplication();
// addition
	void matrixAddition();
// innerproduct
    void innerProduct();
// printMatrix
    void printMatrix(matrix*);
// subtraction
	void matrixSubtraction();
#endif
