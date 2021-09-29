/*
*   Cody Murrer
*   Lab-02
*   9/29/2021
*/

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
    
 // addition
    A.rows = 5;
    A.cols = 5;
    B.rows = 5;
    B.cols = 5;
    C.rows = 5;
    C.cols = 5;
    if(rank == 0){
        initMatrix(&A,A.rows,A.cols);
        initMatrix(&B,B.rows,B.cols);
        populateMatrix(&A,A.rows,A.cols);
        populateMatrix(&B,B.rows,B.cols);
    } 
    C = matrixAddition(&A,&B,world,wSize,rank);

    if(rank == 0){
        printf("--------Matrix A--------\n");
        printMatrix(&A);
        printf("\n--------Matrix B--------\n");
        printMatrix(&B);
        printf("\n--------Matrix Addition Total--------\n");
        printMatrix(&C);

        free(A.data);
        free(B.data);
        free(C.data);
printf("------------------------------------------------\n");
    }
//subtraction
    A.rows = 5;
    A.cols = 5;
    B.rows = 5;
    B.cols = 5;
    C.rows = 5;
    C.cols = 5;
    if(rank == 0){
        initMatrix(&A,A.rows,A.cols);
        initMatrix(&B,B.rows,B.cols);
        populateMatrix(&A,A.rows,A.cols);
        populateMatrix(&B,B.rows,B.cols);
    } 
    C = matrixSubtraction(&A,&B,world,wSize,rank);

    if(rank == 0){
        printf("--------Matrix A--------\n");
        printMatrix(&A);
        printf("\n--------Matrix B--------\n");
        printMatrix(&B);
        printf("\n--------Matrix Subtraction Total--------\n");
        printMatrix(&C);

        free(A.data);
        free(B.data);
        free(C.data);
    printf("------------------------------------------------\n");
    }
//multiplication 
    A.rows = 5;
    A.cols = 5;
    B.rows = 5;
    B.cols = 5;
    C.rows = 5;
    C.cols = 5;
    if(rank == 0){
        initMatrix(&A,A.rows,A.cols);
        initMatrix(&B,B.rows,B.cols);
        populateMatrix(&A,A.rows,A.cols);
        populateMatrix(&B,B.rows,B.cols);
    } 
    C = matrixMutiplication(&A,&B,world,wSize,rank);

    if(rank == 0){
        printf("--------Matrix A--------\n");
        printMatrix(&A);
        printf("\n--------Matrix B--------\n");
        printMatrix(&B);
        printf("\n--------Matrix Multiplication Total--------\n");
        printMatrix(&C);

        free(A.data);
        free(B.data);
        free(C.data);
    printf("------------------------------------------------\n");
    }
// inner product
    A.rows = 5;
    A.cols = 1;
    B.rows = 5;
    B.cols = 1;
    if(rank == 0){
        initMatrix(&A,A.rows,A.cols);
        initMatrix(&B,B.rows,B.cols);
        populateMatrix(&A,A.rows,A.cols);
        populateMatrix(&B,B.rows,B.cols);
    } 
    int innerProdRes = innerProduct(&A,&B,world,wSize,rank);

    if(rank == 0){
        printf("--------Matrix A--------\n");
        printMatrix(&A);
        printf("\n--------Matrix B--------\n");
        printMatrix(&B);
        printf("\n--------Inner Product Total--------\n");
        printf("%d\n",innerProdRes);

        free(A.data);
        free(B.data);
    printf("------------------------------------------------\n");
    }
// transpose    
    A.rows = 5;
    A.cols = 3;

    if(rank == 0){
        initMatrix(&A,A.rows,A.cols);
        populateMatrix(&A,A.rows,A.cols);
    } 
    C = matrixTranspose(&A);

    if(rank == 0){
        printf("--------Matrix A--------\n");
        printMatrix(&A);
        printf("\n--------Transpose Matrix--------\n");
        printMatrix(&C);

        free(A.data);
        free(C.data);
    }

    MPI_Finalize();
    return 0;
}
