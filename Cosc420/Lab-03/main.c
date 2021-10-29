#include"matrix.h"
#include<mpi.h>

int main(int argc, char** argv){
    srand(time(NULL));
    
    MPI_Init(&argc,&argv);
    MPI_Comm world = MPI_COMM_WORLD;
    int wSize, rank;
    MPI_Comm_rank(world,&rank);
    MPI_Comm_size(world,&wSize);

    matrix a;
    matrix b;
    matrix c;
    //if(rank == 0){
        initMatrix(&a,2,2);
        initMatrix(&b,2,2);
       // initMatrix(&c,5,5);
    if(rank == 0){
        populateMatrix(&a,2,2);
        populateMatrix(&b,2,2);
    }
    c = matrixMutiplication(&a,&b,world,wSize,rank);
        if(rank == 0){
	    printMatrix(&a);
	    printf("\n");
	    printMatrix(&b);
	    printf("\n");
            printMatrix(&c);
	}
       // if(rank == 0){
            free(a.data);
            free(b.data);
            free(c.data);
       // }
  //  }
    MPI_Finalize();
    return 0;
}
