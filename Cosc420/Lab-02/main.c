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
//change .row an .col size to change the size of the matrix
    int* arr = malloc(5*sizeof(int));
    arr[0] = 5;
    arr[1] = 10;
    arr[2] = 100;
    arr[3] = 1000;
    arr[4] = 10000;
// testing for add and subtract
    matrix A,B,C;
 // addition
    A.rows = arr[4];
    A.cols = arr[4];
    B.rows = arr[4];
    B.cols = arr[4];
    C.rows = arr[4];
    C.cols = arr[4];
    if(rank == 0){
        initMatrix(&A,A.rows,A.cols);
        initMatrix(&B,B.rows,B.cols);
        populateMatrix(&A,A.rows,A.cols);
        populateMatrix(&B,B.rows,B.cols);
    } 
    C = matrixAddition(&A,&B,world,wSize,rank);

    if(rank == 0){
/*     
        printf("--------Matrix A--------\n");
        printMatrix(&A);
        printf("\n--------Matrix B--------\n");
        printMatrix(&B);
        printf("\n--------Matrix Addition Total--------\n");
        printMatrix(&C);
*/
        free(A.data);
        free(B.data);
        free(C.data);
        printf("Addition Done\n");
//        printf("------------------------------------------------\n");
    }
//subtraction
    A.rows = arr[4];
    A.cols = arr[4];
    B.rows = arr[4];
    B.cols = arr[4];
    C.rows = arr[4];
    C.cols = arr[4];
    if(rank == 0){
        initMatrix(&A,A.rows,A.cols);
        initMatrix(&B,B.rows,B.cols);
        populateMatrix(&A,A.rows,A.cols);
        populateMatrix(&B,B.rows,B.cols);
    } 
    C = matrixSubtraction(&A,&B,world,wSize,rank);

    if(rank == 0){
/*      
        printf("--------Matrix A--------\n");
        printMatrix(&A);
        printf("\n--------Matrix B--------\n");
        printMatrix(&B);
        printf("\n--------Matrix Subtraction Total--------\n");
        printMatrix(&C);
*/
        free(A.data);
        free(B.data);
        free(C.data);
        printf("Subtraction Done\n");
//        printf("------------------------------------------------\n");
    }
//multiplication 
    A.rows = arr[4];
    A.cols = arr[4];
    B.rows = arr[4];
    B.cols = arr[4];
    C.rows = arr[4];
    C.cols = arr[4];
    if(rank == 0){
        initMatrix(&A,A.rows,A.cols);
        initMatrix(&B,B.rows,B.cols);
        populateMatrix(&A,A.rows,A.cols);
        populateMatrix(&B,B.rows,B.cols);
    } 
    C = matrixMutiplication(&A,&B,world,wSize,rank);

    if(rank == 0){
/*
        printf("--------Matrix A--------\n");
        printMatrix(&A);
        printf("\n--------Matrix B--------\n");
        printMatrix(&B);
        printf("\n--------Matrix Multiplication Total--------\n");
        printMatrix(&C);
*/
        free(A.data);
        free(B.data);
        free(C.data);
        printf("Multiplication Done\n");
//        printf("------------------------------------------------\n");
    }
// inner product
    A.rows = arr[4];
    A.cols = arr[4];
    B.rows = arr[4];
    B.cols = arr[4];
    if(rank == 0){
        initMatrix(&A,A.rows,A.cols);
        initMatrix(&B,B.rows,B.cols);
        populateMatrix(&A,A.rows,A.cols);
        populateMatrix(&B,B.rows,B.cols);
    } 
    int innerProdRes = innerProduct(&A,&B,world,wSize,rank);

    if(rank == 0){
/*
        printf("--------Matrix A--------\n");
        printMatrix(&A);
        printf("\n--------Matrix B--------\n");
        printMatrix(&B);
        printf("\n--------Inner Product Total--------\n");
        printf("%d\n",innerProdRes);
*/
        free(A.data);
        free(B.data);
        printf("Inner Product Done\n");
//        printf("------------------------------------------------\n");
    }
// transpose    
    A.rows = arr[4];
    A.cols = arr[4];

    if(rank == 0){
        initMatrix(&A,A.rows,A.cols);
        populateMatrix(&A,A.rows,A.cols);
    } 
    C = matrixTranspose(&A);

    if(rank == 0){
/*
        printf("--------Matrix A--------\n");
        printMatrix(&A);
        printf("\n--------Transpose Matrix--------\n");
        printMatrix(&C);
*/
        free(A.data);
        free(C.data);
        printf("Transpose Done\n");
    }

    MPI_Finalize();
    return 0;
}
