#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLINE 256
void err_sys(char *);

int main(){
    int fd[2];
    int temp,temp2;
    int arg1, arg2;
    pid_t pid;
    char output[MAXLINE];
    char input[MAXLINE];

    if(pipe(fd)<0){ // creates the pip with file descriptors
        err_sys("Pipe Error: Unable to pipe");
    }
    if((pid = fork())<0){ // creates the child process
        err_sys("Fork Error: Unable to fork");
    }else if(pid>0){
        close(fd[0]);
        printf("Enter Two integers to find the sum\n");
        while((temp = read(STDIN_FILENO,input,MAXLINE))>0){ // reads the input
            write(fd[1],input,temp);
            printf("Enter Two integers to find the sum\n");
        }
    }else{
        close(fd[1]);
        while((temp2 = read(fd[0],output,MAXLINE))>0){ // reads from descriptor 0
            if(sscanf(output,"%d%d",&arg1,&arg2)==2){ // checks if ther are two integer values passed
                sprintf(output,"The sum between the two integers are: %d\n",(arg1+arg2)); // prints the sum between the two
                if(write(STDOUT_FILENO,output,strlen(output))!=strlen(output)){ // writes to the standard output
                    err_sys("Write Error: unable to write output");
                }
            }else{
                if(write(STDOUT_FILENO, "Improper input only input two integers\n", 40)!=40){
                    err_sys("Write Error: Improper input cant prouce proper output");
                }
            }
        }
    }
    exit(0);
}

void err_sys(char *str){
    printf("%s\n",str);
    exit(1);
}