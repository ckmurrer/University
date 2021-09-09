/*
    Cody Murrer
    9/8/2021
    Cosc-420 High-Performance Computing
    Lab-01: hello.c
    Desc: Write a hello world using MPI and parallel programming.
*/
#include<stdio.h>
#include<mpi.h>

int main(int argc, char** argv){
    MPI_Init(&argc,&argv);
    MPI_Comm world = MPI_COMM_WORLD;

    int rank,len,size;
    char processor[MPI_MAX_PROCESSOR_NAME];
    MPI_Comm_size(world, &size);
    MPI_Comm_rank(world, &rank);
    MPI_Get_processor_name(processor, &len);

    printf("Hello World! From rank: %d out of %d, Processor: %s.\n",rank,size,processor);

    MPI_Finalize();
    return 0;
}