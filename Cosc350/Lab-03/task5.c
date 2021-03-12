#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>

#define BUFFER_SIZE 1
/*
exit(0) - successful termination
exit(1) - file error termination
*/
int main(){
    int readFile = open("foo",O_RDONLY);
    umask(0);
    int writeFile = open("foorev", O_WRONLY|O_CREAT,S_IRWXU|S_IRGRP|S_IWGRP);
    int counter = -1;
    if(writeFile<0){
        printf("Create file error\n");
        close(readFile);
        exit(1);
    }else if(readFile<0){
        printf("Open file error\n");
        exit(1);
    }
    char buffer[BUFFER_SIZE];
    char temp;

    int size = lseek(readFile,0,SEEK_END);
    lseek(readFile,counter,SEEK_END);
    while((temp=read(readFile,buffer,BUFFER_SIZE))>0){
        if(write(writeFile,buffer,temp)!=temp){
            printf("Write Error\n");
            close(readFile);
            close(writeFile);
            exit(1);
        }else if(counter==size*-1){
            break;
        }
        counter--;
        lseek(readFile,counter,SEEK_END);
    }
    if(temp<0){
        printf("Read Error\n");
        close(readFile);
        close(writeFile);
        exit(1);
    }
    close(readFile);
    close(writeFile);
    exit(0);
}