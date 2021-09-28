#include "matrix.h"

int main(int argc, char** argv){
    MPI_Init(&argc,&argv);
    int wSize,rank;
    MPI_Comm world = MPI_COMM_WORLD;
    MPI_Comm_rank(world,&rank);
    MPI_Comm_size(world,&wSize);

    srand(time(0));
// testing for add and subtract
    matrix A,B,C;
    A.rows = 5;
    A.cols = 5;
    B.rows = 5;
    B.cols = 5;
    C.rows = 5;
    C.cols = 5;
    initMatrix(&A,A.rows,A.cols);
    initMatrix(&B,B.rows,B.cols);
    initMatrix(&C,C.rows,C.cols);
    populateMatrix(&A,A.rows,A.cols);
    populateMatrix(&B,B.rows,B.cols);

    C.data = matrixSubtraction(&A,&B,world,wSize,rank);
    if(rank == 0){
        printf("--------Matrix A--------\n");
        printMatrix(&A);
        printf("\n--------Matrix B--------\n");
        printMatrix(&B);
        printf("\n--------Matrix Addition Total--------\n");
        printMatrix(&C);
    }
    free(A.data); 
    free(B.data);
    free(C.data);
    MPI_Finalize();
    return 0;
}
