#include <stdio.h>
#include <stdlib.h>
#include <mpi.h>
#include <string.h>
#include <time.h>

int main(int argc, char** argv){
    MPI_Init(&argc, &argv);
    MPI_Comm world = MPI_COMM_WORLD;
    int rank, wSize;
    MPI_Comm_size(world,&wSize);
    MPI_Comm_rank(world,&rank);
    MPI_File file;

    const char* fileName = "readFile.txt";
    int size = argc;
    int offset;
    char local[size+1];
    char* buf = malloc(size*(4+1) + 1);
    buf[0] = '\0';

    srand(time(0)+rank);
    int i;
    for(i=0; i< size; i++){
        local[i] = '0'+rand()%10;
    }

    const char* fmt = "%4d ";
    char tmp[4+1 + 1]; // same width as fmt plus a null term

    for(int i=0; i<size; i++){
        sprintf(tmp, fmt, local[i]);
        strcat(buf, tmp);
    }
    free(buf);
    
    MPI_File_open(
        world,
        fileName,
        MPI_MODE_CREATE | MPI_MODE_RDWR,
        MPI_INFO_NULL,
        &file
    );

    offset = size*rank*sizeof(char);

    MPI_File_write(
        file,
       // offset,
        local,
        size,
        MPI_INT,
        MPI_STATUS_IGNORE
    );

    MPI_File_close(&file);

    MPI_Finalize();
    return 0;
}