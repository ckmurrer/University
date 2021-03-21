#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/wait.h>

#define BUFFER_SIZE 1

int check_if_number(char input){
    int number = (int) input;
    if(input >= (int)'0' && input <= (int)'9'){
        return number;
    }
    return 0;
}

int main(int argc, char* argv[]){
    if(argc != 2){
        printf("Argument Error: Too many or not enough arguments passed\n");
        exit(1);
    }

    int infile = open(argv[1],O_RDONLY);
    if(infile <0){
        printf("File Error: Unable to open file\n");
        exit(1);
    }
    int fileSize = lseek(infile,0,SEEK_END);
    
    int parentOut = open("parent.txt",O_WRONLY|O_CREAT,S_IRUSR|S_IWUSR|S_IROTH|S_IWOTH|S_IRGRP|S_IWGRP);
    if(parentOut < 0){
        printf("File Error: Unable to open or create file\n");
        close(infile);
        exit(1);
    }

    int childOut = open("child.txt",O_WRONLY|O_CREAT,S_IRUSR|S_IWUSR|S_IROTH|S_IWOTH|S_IRGRP|S_IWGRP);
    if(childOut<0){
        printf("File Error: Unable to open or create file\n");
        close(infile);
        close(parentOut);
        exit(1);
    }

    int exit_code;
    char buffer;
    
    pid_t pid;
    pid = fork();
    switch(pid){
        case -1:
            perror("fork failed");
            exit(1);
        case 0:
            exit_code = 37;
            printf("Child Process Running\n");
            for(int i=0; i < fileSize; i++){
                lseek(infile,(off_t)i,SEEK_SET);
                read(infile,&buffer,BUFFER_SIZE);
                if(check_if_number(buffer)){
                    printf("Child Process writing to file\n");
                    write(childOut,&buffer,BUFFER_SIZE);
                }
            }
                printf("Child done writing to file\n");
        break;
        default:
            exit_code = 0;
            printf("parent Process Running\n");
            for(int i=0; i < fileSize; i++){
                lseek(infile,(off_t)i,SEEK_SET);
                read(infile,&buffer,BUFFER_SIZE);
                if(check_if_number(buffer)==0){
                    printf("Parent Process writing to file\n");
                    write(parentOut,&buffer,BUFFER_SIZE);
                }
            }
            printf("Parent done writing to file\n");
        break;
    }
    close(infile);
    close(parentOut);
    close(childOut);

    if (pid != 0) {
        int stat_val;
        pid_t child_pid;
        child_pid = wait(&stat_val);
        printf("Child has finished: PID = %d\n", child_pid);
        if(WIFEXITED(stat_val))
        printf("Child exited with code %d\n", WEXITSTATUS(stat_val));
        else
        printf("Child terminated abnormally\n");
    }
    exit(exit_code);
}
