#include <stdlib.h> 
#include <sys/types.h>
#include <stdio.h> 
#include <signal.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h> 

int READ_END = 0;
int WRITE_END = 1;

void syncro(int sig) {
    if(sig == SIGUSR1) {
        // sigusr1 for syncronization
    }
}

int main() {
    umask(0);
    int finalPipe[2];

    pipe(finalPipe);

    int fileDesOne = open("foo", O_CREAT | O_RDWR, 0666);
    int fileDesTwo = dup(fileDesOne);
    pid_t pid = fork(); 

    signal(SIGUSR1, syncro); 

    if(pid == 0) { 
        write(fileDesTwo, "Hi, Mom", 7);
        close(fileDesTwo);

        kill(getppid(), SIGUSR1);
        pause();

        close(finalPipe[WRITE_END]);

        char buffer[18];
        if(read(finalPipe[READ_END], buffer, 18) > 0) {
            printf("My Mom said %s\n", buffer);
            close(finalPipe[READ_END]);
        }
        return 0;
    } else {
        pause();
        lseek(fileDesOne, SEEK_SET, 0);

        char readBuffer[7];
        read(fileDesOne, readBuffer, 7);
        printf("My son said %s\n", readBuffer);

        close(fileDesOne);
        close(finalPipe[READ_END]);

        char msgBuffer[18] = "what do you want\0";
        write(finalPipe[WRITE_END], msgBuffer, 18);
        
        kill(pid, SIGUSR1);

        close(finalPipe[WRITE_END]);
    }

    return 0;
}