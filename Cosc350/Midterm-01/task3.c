#include <stdlib.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

#define BUFFER_SIZE 1
// converts the passed char variable to an int 
int str_to_int(char *input){ 
    int number = 0; 
    int position = 0; 
    while(input[position] != '\0'){ 
        number = (10 * number) + (input[position] - '0'); 
        position++; 
    } 
    return number; 
} 
// converts the passed integer variable to a string value
char *int_to_str(int input){
    int sizeOfInput=0;
    int num = input;
    int temp;
    char* chBuff;
// gets size of int (how many integer places)    
    while(num){
        sizeOfInput++;
        num = num/10;
    }
// dynamically allocates the size of a char pointer to the size of the int * the size of char    
    chBuff=malloc(sizeOfInput*sizeof(char));
// converts the integer passed to a string value and adds it to the char pointer
    for(int i=0; i<sizeOfInput; i++){
        temp = input%10;
        chBuff[(sizeOfInput-i)-1]=temp+'0';
        input = input/10;
    }
    return chBuff;
}
// checks if the passed variable is a number
int check_if_number(char input){
    int number = (int) input;
    if(input >= (int)'0' && input <= (int)'9'){
        return number;
    }
    return 0;
}

int main(int argc, char* argv[]){
    if(argc != 2){
        printf(" too many or not enough arguments passed");
        exit(1);
    }
// sets the readFile equal to the 1st passed argument through the command line    
    int readFile = open(argv[1], O_RDONLY);
    if(readFile == -1){
        printf("File Error: cannot open file");
        exit(1);
    }

    char buffer[BUFFER_SIZE];
    char input[80];
    int temp;
    int pos = 0;
// reads the readFile and puts it into the buffer    
    while((temp=read(readFile,buffer,BUFFER_SIZE)>0)){
// checks if the buffer contains any integers and if so put them into a char array of size 80        
        if(check_if_number(buffer[0])){
            input[pos] = buffer[0];
            pos++;
        } 
    }    
    int convertInt = str_to_int(input); // creates a new variable equal to the return value of the string to int method
    convertInt += 100;
    write(1,int_to_str(convertInt), pos); // writes the return of integer to string conversion method to the standard output
    printf("\n");
    close(readFile);
    exit (0);
}