#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>

#define BUFFER_SIZE 1

int palind(int fd1, int fd2){
// find the length of the file and sets it back to the start
    int length = lseek(fd2, 0, SEEK_END);
    lseek(fd2,0,SEEK_SET);

    char forward[length];
    char reverse[length];
// reads both files and sets them to the forward and reverse char arrays
    read(fd1,forward,length);
    read(fd2,reverse,length);
// loops through both arrays comparing the two
    for(int i=0; i<length; i++){
        if(forward[i]!=reverse[(length-1)-i]){
            return 0;
        }
    }
    return 1;
}

int main(int argc, char* argv[]){
// checks if there is enough arguments passed    
    if(argc != 2){
        printf("There are too many or too little arguments passed\n");
        return 1;
    }

    char* input = argv[1];
    int filedes[2];
// opens file and checks if it can be opened
    filedes[0] = open(input, O_RDONLY);
    if(filedes[0] == -1){
        printf("File Error: File can not be opened\n");
        return -1;
    }
// opens the file again and checks if it can be opened
    filedes[1] = open(input, O_RDONLY);
    if(filedes[1] == -1){
        printf("File Error: File can not be opened\n");
        close(filedes[0]);
        return -1;
    }
// calls the palindrome function to check if it is a palindrome
    if(palind(filedes[0], filedes[1]) == 1){
        printf("The file contains a palindrome\n");
    }else{
        printf("This file does not contain a palindrome!\n");
    }
// closes the open files and exits successfully
    close(filedes[0]);
    close(filedes[1]);
    return 0;
}