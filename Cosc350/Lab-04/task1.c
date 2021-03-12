#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>

#define BUFFER_SIZE 1
// from lab 3 task 7
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
// takes in two file arguments from console 
// file one is a file filled with ascii
// file two is an output file that get written
// with the converted chars from the ascii text  
int main(int argc, char* argv[]){
// checks to see if there is enough arguments passed    
    if(argc != 3){
        printf("Argument Error: Too many or Too little arguments passed.");
        exit(1);
    }

    char buffer[BUFFER_SIZE],writeBuffer[4];
    char temp;
    int pos = 0; 
// opens the read file if not able to open prints file error and exits
    int readFile = open(argv[1],O_RDONLY);
    if(readFile<0){
        printf("File Error: unable to open file");
        exit(1);
    }
// opens the write file if not able to open prints file error closes
// the read file then exits
    int writeFile = open(argv[2],O_WRONLY|O_CREAT,S_IRUSR|S_IWUSR);
    if(writeFile<0){
        printf("File Error: unable to open or create file");
        close(readFile);
        exit(1);
    }
// redirects the output of prints to file descriptor one
    dup2(writeFile,1);
// reads the input file 
    while (read(readFile,&buffer,BUFFER_SIZE)>0){    
       if(buffer[0] == ' '){ // checks if there is a space after the ascii char
            writeBuffer[pos] = '\0'; // ends string
            printf("%c",int_to_char(writeBuffer)); // converts the buffer to a char value and writes to file
            pos = 0;
        }else if(buffer[0] == '\n'){ // checks if there is a new line
            printf("\n"); // writes a new line in the output file
        }else if(buffer[0] != ' '){ // checks if there is not a space
            writeBuffer[pos] = buffer[0]; // adds the current position of the buffer to the write buffer
            pos++;
        }else{ // if none of these conditions are met then closes both files and prints a file error then exits
            close(readFile);
            close(writeFile);
            printf("File Error\n");
            exit(1);
       }
    }
    exit(0);
}