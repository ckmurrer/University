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

}
// does not exceed 4 characters
void prefix(char dicWord[],int start, int end, int rank){
	char buffer[255] ;
	int count = 0, inc = 0;
	int	temp = start,temp2;
	int arr[100];
// partitions the amount of operations needed per node rank*(9999/wSize)	
	if(start <10){
		sprintf(buffer,"0%s",dicWord);
		buffer[0]+=start;	
	}
	while(temp!=0){
		if(start >9 && start < 100){
			sprintf(buffer,"00%s",dicWord);
			if(inc == 2){
				temp = 0;
			}
			temp2 = temp % 10;
			arr[inc] = temp2;
			buffer[0]+=arr[1];
			buffer[1]+=arr[0];
			temp = temp/10;
			inc++;
		}	
		if(start >99 && start < 1000){
			sprintf(buffer,"000%s",dicWord);
			if(inc == 3){
				temp = 0;
			}
			temp2 = temp % 10;
			arr[inc] = temp2;
			buffer[0]+=arr[2];
			buffer[1]+=arr[1];
			buffer[2]+=arr[0];
			temp = temp/10;
			inc++;
		}
		if(start >999 && start < 10000){
				sprintf(buffer,"0000%s",dicWord);
			if(inc == 4){
				temp = 0;
			}
			temp2 = temp % 10;
			arr[inc] = temp2;
			buffer[0]+=arr[3];
			buffer[1]+=arr[2];
			buffer[2]+=arr[1];
			buffer[3]+=arr[0];
			temp = temp/10;
			inc++;
		}
	}

	int i,k,pls=0,work=0,maybe = 0,boop = 0, check = 0;
	for(k = start; k < end;k++){
		count = 0;
		for(i=0; i< 10; i++){
			if(count!=10&&k==0){
			printf("%s",buffer);
				buffer[0]++;
				count++;
			}
			if(k<10 && k!=0){
				if(count==0&&k>1){
					buffer[1] -= 10;
					count++;
				}
				if(i<10){
					printf("%s",buffer);
					buffer[1]++;
				}
			}

		}
		if(k<10){
			if(pls==0){
				sprintf(buffer,"00%s",dicWord);
				pls++;
			}
			
			if(maybe!=0){
				if(work!=10){
					buffer[0]++;
					work++;
				}	
			}
			maybe++;
		}
/*

		if(k>10&&k<20){
			if(boop==0){
				sprintf(buffer,"000%s",dicWord);
				boop++;
			}
			if(check!=9){
				buffer[0]++;
				check++;
			}
		}
		*/
	}
}

void test(char shadow[], int start, int end, int rank){
	int temp = 2000;
	prefix(shadow,start,end, rank);
	//printf("Rank: %d --- %s",rank,shadow);
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
	char id[11][100];
	char salty[11][100];
	char hash[11][100];
	char users[11][100];
	char buffer[255];
	char dicBuffer[255];
	char seed[11][100];
	char *temp;
	char buf[11][100];
	char words[1][100];
	FILE* shadow = fopen("shadow","r");
	int i = 0;
// spent 5 HOURS PLUS ON THIS ALONE
	while(fgets(buffer, 255 , shadow)){
		strcpy(buf[i],buffer);
		temp = strtok(buf[i],"$");
   		while( temp != NULL ) {
			if(count == 0){				//extracts the username from file
				strcpy(users[i],temp);
			}else if (count == 1){		//extracts the ID from the file
				strcpy(id[i],temp);
			}else if(count == 2){		//gets the salt and puts in $id$salt$ format
				strcpy(seed[i],"$");
				strcat(seed[i],id[i]);
				strcat(seed[i],"$");
				strcpy(salty[i],temp);
				strcat(seed[i],salty[i]);
				strcat(seed[i],"$");
			}else if(count == 3){		//gets already hashed password
				strcpy(hash[i],temp);
			}	
			count++;
			temp = strtok(NULL, "$");
   		}
	//	printf("%s --- %s ---%s",users[i],seed[i],hash[i]);
		count = 0;
		i++;
	}

	int maxSize = 9999;
	int operations = (maxSize/wSize);
	int start = rank*operations;
	int end = start+operations;

	int j = 0;
	FILE* dictionary = fopen("words.txt","r");
	while(fgets(dicBuffer,255,dictionary)){
		strcpy(words[0],dicBuffer);
		test(words[0],start,end, rank);
	}

//	printf("rank = %d\nmax = %d\noperations = %d\nstart = %d\nend = %d\n",rank,maxSize,operations,start,end);

	fclose(dictionary);
	fclose(shadow);
	MPI_Finalize();
	return(0);
}
