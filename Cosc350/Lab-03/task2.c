#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>

int main(){
    int readFile = open("foo",O_RDONLY);
    if(readFile<0){
        printf("File Error file non existent or not readable\n");
        exit(1);
    }

    umask(0);
    int writeFile = open("clone1",O_WRONLY|O_CREAT, S_IRUSR|S_IWUSR| S_IRGRP| S_IWGRP| S_IROTH| S_IWOTH);
    if(writeFile<0){
        printf("File Error file could not be opened or created\n");
        close(readFile);
        exit(1);
    }
    char pointer;

    while (read(readFile, &pointer,1) == 1){
        write(writeFile,&pointer,1);   
    }
    close(readFile);
    close(writeFile);
    exit(0);
}