#include "matrix.h"

int main(int argc, char** argv){
    MPI_Init(&argc,&argv);
       
    matrix A;
    A.rows = 5;
    A.cols = 5;

    initMatrix(&A,A.rows,A.cols);
    int i,j; 
    srand(time(0));
    for(i=0;i<A.rows;i++){
        for(j=0;j<A.cols;j++){
	    ACCESS(A,i,j) = rand()%10+1;
	}    
    }

    matrix B;
    B.rows = 5;
    B.cols = 5;
    
    initMatrix(&B,B.rows,B.cols);
    for(i=0; i<B.rows; i++){
	for(j=0; j<B.cols;j++){
	    ACCESS(A,i,j) = rand()%10+1;
	}
    }


    printMatrix(&A);
printf("\n");
    printMatrix(&B);
    
    free(B.data);
    free(A.data);

    MPI_Finalize();
    return 0;
}
