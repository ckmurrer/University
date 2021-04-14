#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

int READ_END = 0;
int WRITE_END = 1;

int main(){

    int firstPipe[2]; 
    int secondPipe[2];

    if (pipe(firstPipe) < 0){
        printf("Pipe Error: could not open the first pipe\n");
    }

    if (pipe(secondPipe) < 0){
        printf("Pipe Error: Could not open the second pipe\n");
    }

    pid_t child = fork();

    if (child == 0){

        close(firstPipe[READ_END]);
        close(secondPipe[WRITE_END]);

        char childMessage[] = "Hi, Mom";
        char bufferChild[11];

        write(firstPipe[WRITE_END], childMessage, 8); 
        close(firstPipe[READ_END]);

        if (read(secondPipe[READ_END], bufferChild, 11) > 0){
            printf("My mom said %s\n", bufferChild);
            close(secondPipe[WRITE_END]);
        }

    }else if (child > 0){ 

        close(firstPipe[WRITE_END]);
        close(secondPipe[READ_END]);

        char parentMessage[] = "I love you";
        char bufferParent[8];

        if (read(firstPipe[READ_END], bufferParent, 8) > 0){ 
            printf("My child said %s\n", bufferParent);
            close(firstPipe[READ_END]);
        }

        write(secondPipe[WRITE_END], parentMessage, 11); 
        close(secondPipe[WRITE_END]);
    }

  return 0;
}