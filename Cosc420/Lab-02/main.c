#include "matrix.h"

int main(int argc, char** argv){
    MPI_Init(&argc,&argv);

    matrix A;
    A.rows = 5;
    A.cols = 5;

    initMatrix(&A,A.rows,A.cols);
    printMatrix(&A);

    free(A.data);
    MPI_Finalize();
    return 0;
}