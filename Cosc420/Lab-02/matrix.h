#ifndef MATRIX_H
#define MATRIX_H

#define INDEX(i,j,n,m) i*m+j
#define ACCESS(A,i,j) A.data[INDEX(i,j,A.rows,A.cols)]

typedef struct matrix{
    int rows;
    int cols;
    int* data;
}matrix;

// addition

// subtraction

// multiplication

// innerproduct

#endif