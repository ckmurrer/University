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
    int writeFile = open("foorev1", O_WRONLY|O_CREAT,S_IRWXU|S_IRGRP|S_IWGRP);
    int count = 0;
    if(writeFile<0){
        printf("Create file error\n");
        exit(1);
    }else if(readFile<0){
        printf("Open file error\n");
        exit(1);
    }
    char buffer[BUFFER_SIZE];
    // gets size of file
    while(read(readFile,buffer,BUFFER_SIZE)==1){
        count++;
    }
    // reads file in reverse
    while(count > 0){
        pread(readFile,buffer,BUFFER_SIZE,count-1);
        write(writeFile,buffer,BUFFER_SIZE);
        count--;        
    }
    close(readFile);
    close(writeFile);
    exit(0);
}