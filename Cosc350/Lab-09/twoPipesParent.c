#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/wait.h>

#define WRITE_END 1

int main(){
    int data_processed, data_read;
    int file_pipes[2], otherPipes[2];
    
    const char some_data[] = "Hi there kiddo";
    char buffer[BUFSIZ + 1],readBuf[BUFSIZ+1],writeBuf[BUFSIZ+1];
    memset(buffer, '\0', sizeof(buffer));
    
    pid_t fork_result;

    if (pipe(file_pipes) == 0 && pipe(otherPipes) == 0) {
        fork_result = fork();
        if (fork_result == (pid_t)-1) {
            fprintf(stderr, "Fork failure");
            exit(EXIT_FAILURE);
        }
        if (fork_result == 0){
            close(file_pipes[1]);
            close(otherPipes[0]);
            sprintf(readBuf, "%d", file_pipes[0]);
            sprintf(writeBuf, "%d", otherPipes[1]);
            (void)execl("twoPipesChild", "twoPipesChild", readBuf, writeBuf, (char *)0);
            exit(EXIT_FAILURE);
        }else{
            close(file_pipes[0]);
            close(otherPipes[1]);
            data_processed = write(file_pipes[WRITE_END], some_data,strlen(some_data));
            data_read = read(otherPipes[0],buffer,6);
            printf("Parent %d sent %d bytes to child\n",getgid(),14);
            wait(&fork_result);
            printf("Parent (%d) recieved the message %s made of %d bytes. \n", getpid(), buffer, data_read);
        }
    }
    exit(EXIT_SUCCESS);
}