/*
    Cody Murrer
    9/8/2021
    Cosc-420 High-Performance Computing
    Lab-01: bigNumbers.c 
    Desc: Find the primality of a given user input using Parallel Programming.
*/
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<mpi.h>

int main(int argc, char** argv){
    MPI_Init(&argc, &argv);

    if(argc != 2){
        printf("Invalid user input terminating program.\n");
        return 0;
    }

    int wSize, rank;
    MPI_Comm world = MPI_COMM_WORLD;
    MPI_Comm_size(world, &wSize);
    MPI_Comm_rank(world, &rank);

    unsigned long long usrInput = atoll(argv[1]);
    unsigned long long rootInput = sqrt(usrInput);

    unsigned long long startSpot, endSpot;
    endSpot = (((rank+1)*rootInput)/wSize); // formula given by Dr. Anderson during office hours.
    // checks if rank is 0 and if so will make loop start at two when it is ran for rank 0.
    if(rank == 0){
        startSpot = ((rank*rootInput)/wSize)+2;
    }else{
        startSpot = ((rank*rootInput)/wSize)+1;// formula given by Dr. Anderson during office hours added one to have node start on k+1 .
    }
    printf("Rank: %d starts at: %llu, and ends at: %llu.\n",rank,startSpot,endSpot); // prints the range of number the range checks.

    int divFound;
    unsigned long long i;
    for(i=startSpot; i<=endSpot; i++){
        // checks if the number is prime and if so then print out the first divisor for each rank that is found then break.
        if(i == 1||i == 0){
            continue;
        }
        if(usrInput%i==0){
            printf("DIVISOR FOUND... Rank: %d found a divisor of %llu.\n",rank,i); // prints found divisor.
            divFound = 1;
            break;
        }else{
            divFound = 0;
        }
    }
    if(divFound == 0){
        printf("NO DIVISOR FOUND with Rank: %d, number is prime if no others found.\n",rank); // prints if a rank finds no divisor.
    }

    MPI_Finalize();
    return 0;
}
