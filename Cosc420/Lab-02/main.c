#include "matrix.h"

int main(int argc, char** argv){
    MPI_Init(&argc,&argv);
       
    matrix A;
    A.rows = 5;
    A.cols = 5;

    initMatrix(&A,A.rows,A.cols);
    int i,j;
    for(i=0;i<A.rows;i++){
        for(j=0;j<A.cols;j++){
	    ACCESS(A,i,j) = rand()%10+1;
	}    
    }

    printMatrix(&A);

    free(A.data);
    MPI_Finalize();
    return 0;
}
