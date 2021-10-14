/*
	Name: Cody Murrer
	Date: 10/12/2021
	Project-01
	Due: 10/17/2021
*/
#define _XOPEN_SOURCE

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<time.h>
#include<mpi.h>

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

int main(int argc, int** argv){
	MPI_Init(NULL,NULL);
	
	int wSize, rank;
	MPI_Comm world = MPI_COMM_WORLD;
	MPI_Comm_size(world, &wSize);
	MPI_Comm_rank(world,&rank);

	int dicNumber = 23588;
	int shadNumber = 11;
	int count = 0;
	char word[11][100];
	char buffer[255];
	FILE* shadow = fopen("shadow","r");
	int i = 0;
// spent 5 HOURS ON THESE 4 LINES I HATE C STRINGS
	while(fgets(buffer, 255 , shadow)){
		strcpy(word[i],buffer);
		printf("%s",word[i]);
		i++;
	}

	FILE* dictionary = fopen("words.txt","r");
	//printf("%s",word);
	if(rank == 0){

		
	}

// Ask how to read/distribute the file
	// opens up dictionary file

	char* test = "test";

	int maxSize = 9999;
	int operations = (maxSize/wSize);
	int start = rank*operations;
	int end = start+operations;

	//printf("rank = %d\nmax = %d\noperations = %d\nstart = %d\nend = %d\n",rank,maxSize,operations,start,end);

	
	fclose(shadow);
	MPI_Finalize();
	return(0);
}
