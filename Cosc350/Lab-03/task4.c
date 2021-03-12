#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>

#define BUFFER_SIZE 1
int main(){

    int readFile = open("foo",O_RDONLY);
    if(readFile<0){
        printf("File Error file does not exist or could be opened\n");
        exit(1);
    }

    int readFile2 = open("foo1",O_RDONLY);
    if(readFile2<0){
        printf("File Error file does not exist or could be opened\n");
        exit(1);
    }

    umask(0);
    int writeFile = open("foo12",O_WRONLY|O_APPEND|O_CREAT, S_IRWXU|S_IRGRP|S_IWGRP);
        if(writeFile<0){
        printf("File Error file could not be created or opened\n");
        close(readFile);
        close(readFile2);
        exit(1);
    }

    char buffer[BUFFER_SIZE];
    char temp;
    
    while ((temp=read(readFile,buffer,BUFFER_SIZE)) > 0){
       if(write(writeFile,buffer,temp) != temp){
           printf("Write Error\n");
           close(readFile);
           close(readFile2);
           close(writeFile);
           exit(1);
       }   
    }
    if(temp < 0){
        printf("Read Error\n");
        close(readFile);
        close(readFile2);
        close(writeFile);
        exit(1);
    }

    close(readFile);
    lseek(writeFile,0,SEEK_END);
    while ((temp=read(readFile2,buffer,BUFFER_SIZE)) > 0){
       if(write(writeFile,buffer,temp) != temp){
           printf("Write Error\n");
           close(readFile);
           close(readFile2);
           close(writeFile);
           exit(1);
       }   
    }
    if(temp < 0){
        printf("Read Error\n");
        close(readFile);
        close(readFile2);
        close(writeFile);
        exit(1);
    }
    close(readFile);
    close(readFile2);
    close(writeFile);
    exit(0);
}