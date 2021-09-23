#ifndef MATRIX_H
#define MATRIX_H

#define INDEX(i,j,n,m) i*m+j
#define ACCESS(A,i,j) A.data[INDEX(i,j,A.rows,A.cols)]

typedef struct matrix{
    int rows;
    int cols;
    int* data;
}matrix;

// initMatrix
	void initMatrix(matrix* A, int rows, int cols);
// addition
	void matrixAddition();
// subtraction
	void matrixSubtraction();
// multiplication
	void matrixMutiplication();
// innerproduct
	
#endif
