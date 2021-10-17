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
		create the suffix from 0000-9999
		create a hashing method that will append the suffix or prefix to the dictionary word and compare with hashed password from shadow file
		figure out how to tell other nodes a hash has been found and not to check that one anymore 
		figure our how to possibly make save points
*/

int char_to_int(char* input){
    int trans = 0; 
    int pos = 0;
// checks to see if there is a char in the input stream
// that can be translated into ascii
    while(input[pos] != '\0'){
       trans = (10 * trans) + (input[pos]-'0');
       pos++;
    }
    return trans;
}
// calls the above method to change the passed char to an int value
// then changes that int value to a corresponding char then returns
char int_to_char(char *input){
    int number = char_to_int(input); // calls the char to int conversion method
    char textVal = number; 
    return textVal;
}


// does not exceed 4 characters
void suffix(char buff []){
	printf("%s",buff);
}

// does not exceed 4 characters
char prefix(char dicWord[],int start, int end, int rank,int wSize,char stopOp[]){
	char buffer[255];
	int count = 0, inc = 0;
	int stop = start*wSize;
	int	temp = start,temp2;
	//char stopOp[100];
	char arr[100];
	int arr2[100];
	int x = 0;

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
				arr2[inc] = temp2;
				arr[inc] = arr2[inc];
				buffer[0]+=arr[1];
				buffer[1]+=arr[0];
				temp = temp/10;
				inc++;
			}	
			if(start >100 && start < 1000){
				sprintf(buffer,"000%s",dicWord);
				if(inc == 3){
					temp = 0;
				}
				temp2 = temp % 10;
				arr2[inc] = temp2;
				arr[inc] = arr2[inc];
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
				arr2[inc] = temp2;
				arr[inc] = arr2[inc];
				buffer[0]+=arr[3];
				buffer[1]+=arr[2];
				buffer[2]+=arr[1];
				buffer[3]+=arr[0];
				temp = temp/10;
				inc++;
			}
		}
	
	int i,k,pls=0,work=0,maybe = 0,boop = start, check = start;
	for(k = start; k < end;k++){
		for(i=0; i < 10; i++){
			if(k<9){
				count = 0;
				if(count!=10&&k==start){
					suffix(buffer);
					buffer[0]++;
					x++;
					count++;
				}
			}
			if(k>start+9 && k < start+20 && inc<3){
				if(x==10){
					sprintf(buffer,"00%s",dicWord);
					count = 0;
					x++;
					
				}
				if(maybe == 0 && x!=11){
					buffer[1] -= arr2[0];
					count = 0;
					maybe ++;
				}
				if(count == 0 && k!=start+10){
					buffer[1]-=10;
				}		
				if(count != 10){
					suffix(buffer);
					buffer[1]++;
					count++;
				}
				if(count == 10){
					buffer[0]++;
					count = 0;
				}
			}
			if(k>start+19 && k<start+100){

				if(x==11){
					sprintf(buffer,"000%s",dicWord);
					count = 0;
					x++;
				}

				if(maybe == 0 && x!=12){
					buffer[2] -= arr2[1];
					buffer[1] -= arr2[2];
					count = 0;
					maybe ++;
				}
				if(count == 0 && k!=start+20){
					buffer[2]-=10;
					
				}		
				if(count != 10){
					suffix(buffer);
					buffer[2]++;
					count++;
				}
				if(count == 10){
					buffer[1]++;
					work++;
					count = 0;
				}
				if(work == 10){
					buffer[0]++;
		
					buffer[1]-=10;
					
					work = 0;
				}
			}/*
			if(k>start+99 && k<start+1000){
				if(pls==2){
					sprintf(buffer,"0000%s",dicWord);
					count = 0;
					pls++;
				}

				if(count == 0 && k!=start+100){
					buffer[3]-=10;
				}	
				if(count != 10){
					suffix(buffer);
					buffer[3]++;
					count++;
				}
				if(count == 10){
					buffer[2]++;
					work++;
					count = 0;
				}
				if(work == 10){
					buffer[1]++;
					buffer[2]-=10;
					boop++;
					work = 0;
				}
				if(boop == 10){
					buffer[0]++;
					buffer[1]-=10;
					boop = 0;
				}
			}*/
		}	
	
		if(buffer[0] == stopOp[0]){
			break;
		}
		//printf("%s",stopOp);
	}
		
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

	int maxSize = 1000;
	int operations = (maxSize/wSize);
	int start = rank*operations;
	int end = start+operations;

	int try = end;
	char t2;
	char stopPoint[4];
	while(try){
		t2=try%10;
		try/=10;
	}
	sprintf(stopPoint,"%d",t2);
	
	int j = 0;
	FILE* dictionary = fopen("test.txt","r");
	while(fgets(dicBuffer,255,dictionary)){
		strcpy(words[0],dicBuffer);
		prefix(words[0],start,end, rank,wSize, stopPoint);
	}

	printf("rank = %d\nmax = %d\noperations = %d\nstart = %d\nend = %d\ntemp = %s\n",rank,maxSize,operations,start,end,stopPoint);

	fclose(dictionary);
	fclose(shadow);
	MPI_Finalize();
	return(0);
}
