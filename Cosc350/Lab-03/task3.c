#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>

#define BUFFER_SIZE 32
int main(){
    char buffer[BUFFER_SIZE];
    int readFile = open("foo",O_RDONLY);
    if(readFile<0){
        printf("File Error file does not exist or could be opened");
        exit(1);
    }
    umask(0);
    int writeFile = open("clone2",O_WRONLY|O_CREAT, S_IRWXU| S_IRWXG);
    if(writeFile<0){
        printf("File Error file could not be created or opened");
        close(readFile);
        exit(1);
    }
    int temp;

    while((temp=read(readFile,buffer,BUFFER_SIZE))>0){
        if (write (writeFile, buffer, temp) !=temp){
            printf("Error writing to file");
            close(readFile);
            close(writeFile);
            exit(1);
        }
    }
    if(temp < 0){
        printf("Error reading the file");
        close(readFile);
        close(writeFile);
        exit(1);
    }
    close(readFile);
    close(writeFile);
    exit(0);
}