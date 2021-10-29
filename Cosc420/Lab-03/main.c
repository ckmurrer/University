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
int check = 0;
    //if(rank == 0){
        initMatrix(&a,5,5);
        initMatrix(&b,5,5);
      //  initMatrix(&c,5,5);
    if(rank == 0){
        populateMatrix(&a,5,5);
        populateMatrix(&b,5,5);
    }
	c = matrixMutiplication(&a,&b,world,wSize,rank);
    //check = innerProduct(&a,&b,world,wSize,rank);
    if(rank == 0){
	    printMatrix(&a);
	    printf("\n");
	    printMatrix(&b);
	    printf("\n");
        printMatrix(&c);
	}

    free(a.data);
    free(b.data);
    //free(c.data);

    MPI_Finalize();
    return 0;
}
