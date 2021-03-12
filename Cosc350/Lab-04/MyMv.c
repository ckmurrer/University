#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(int argc, char *argv[]){
    if(argc != 3){
        printf("Argument Error: too little or too many arguments\n");
        return 1;
    }
// checks the stat for the input file    
    struct stat buff;
    if(stat(argv[1],&buff) < 0){
        printf("Stat Error\n");
        return 1;
    }
// checks if it is a Dir or not    
    if(S_ISDIR(buff.st_mode)){
        if(link(argv[1],argv[2]) == -1){
            printf("File Link Error: unable to link to file\n");
            return 1;
        }
        if(unlink(argv[1]) == -1){
            printf("File Unlink Error: unable to unlink file\n");
            return 1;
        }
    }else{
         if(link(argv[1],argv[2]) == -1){
            printf("File Link Error: unable to link to file\n");
            return 1;
        }
        if(unlink(argv[1]) == -1){
            printf("File Unlink Error: unable to unlink file\n");
            return 1;
        }
    }
    return 0;
}