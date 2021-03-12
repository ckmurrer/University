#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>

#define BUFFER_SIZE 1

int main(int argc, char* argv[]){
    if(argc != 3){
        printf("Error there are not enough or too many arguments\n");
        exit(1);
    }

    int readFile = open(argv[1],O_RDONLY);
    if(readFile<0){
        printf("Error file could not be opened\n");
        exit(1);
    }
    
    umask(0);
    int writeFile = open(argv[2],O_WRONLY|O_CREAT,S_IRUSR|S_IWUSR|S_IRGRP|S_IWGRP|S_IROTH|S_IWOTH);
    if(writeFile<0){
        printf("Error file could not be opened or created\n");
        exit(1);
    }

    char buffer;
    int temp;
    dup2(writeFile,1);
    while (read(readFile,&buffer,BUFFER_SIZE)==1){
        temp = (int)buffer;
        if (temp == 10){ // ten in ascii is new line
            printf("\n");
        }else if (temp == ' '){ // space in ascii is 32
            printf("%d ", temp);
        }else if (temp != ' '){ // if its not a space or enter then
            printf("%d ", temp);// due to dup2 it will print to file
        }else{
            printf("File Error\n");
            close(readFile);
            close(writeFile);
            exit(1);
        }
    }
    close(readFile);
    close(writeFile);
    exit(0);
}