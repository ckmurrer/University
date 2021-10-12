/*
	Name: Cody Murrer
	Date: 10/12/2021
	Project-01
	Due: 10/17/2021
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<time.h>
#include<mpi.h>

#define _XOPEN_SOURCE

/*	
	TODO:
		figure out how to read the text docs and send windows of data to nodes
		let every node open the hash text doc
		figure out how to split hashed text from usernames (possibly by using colon ascii code)
		create the suffix and prefix methods from 0000-9999
		create a hashing method that will append the suffix or prefix to the dictionary word and compare with hashed password from shadow file
		figure out how to tell other nodes a hash has been found and not to check that one anymore 
		figure our how to possibly make save points
*/



// does not exceed 4 characters
void suffix(){
	char* salt = "$1$ab";

}
// does not exceed 4 characters
void prefix(){
	char* salt = "$1$ab";

}


int main(int* argc, int** argv){
	MPI_Init(&argc,&argv);
	
	int wSize, rank;
	MPI_Comm world = MPI_COMM_WORLD;
	MPI_Comm_size(world, &wSize);
	MPI_Comm_rank(world,&rank);
	MPI_File dicFile;
	MPI_File hashFile;
/*
	int *send = NULL;
	int lineNumber = 23588;
*/

// Ask how to read/distribute the file
	// opens up dictionary file
/*	if(rank == 0){
		MPI_File_open(
			world,
			"words.txt",
			MPI_MODE_RDONLY,
			MPI_INFO_NULL,
			&dicFile
		);
	}
	// open up hash text file
	MPI_File_open(
		world,
		"shadow",
		MPI_MODE_RDONLY,
		MPI_INFO_NULL,
		&hashFile
	);
*/
	char* test = "test";

	int maxSize = 9999;
	int operations = (maxSize/wSize);
	int start = rank*operations;
	if(rank % 2 != 0){
		start = rank*operations+1;
	}
	int end = start+operations;

	//printf("rank = %d\nmax = %d\noperations = %d\nstart = %d\nend = %d\n",rank,maxSize,operations,start,end);

	MPI_Finalize();
	return(0);
}
