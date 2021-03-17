#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>

int char_to_int(char *input){ 
    int number = 0; 
    int position = 0; 
    while(input[position] != '\0'){ 
        number = (10 * number) + (input[position] - '0'); 
        position++; 
    } 
    return number; 
} 

int main(int argc, char* argv[]){
    if(argc != 5){
        printf("Argument Error: Too many or too little arguments passed\n");
        printf("Command should be ./task2 [Nc] [Np] [Tc] [Tp]\n");
        exit(1);
    }

    pid_t pid;
    char *message;
    int n,temp, exit_code;
    int Nc = char_to_int(argv[1]), Np = char_to_int(argv[2]), Tc = char_to_int(argv[3]), Tp = char_to_int(argv[4]);
    printf("fork program starting\n");

    pid = fork();
    switch(pid){
        case -1:
            perror("fork failed");
            exit(1);
        case 0:
            message = "This is the child";
            n = Nc;
            temp = Tc;
            exit_code = 37;
        break;
        default:
            message = "This is the parent";
            n = Np;
            temp = Tp;
            exit_code = 0;
            wait(&pid);
        break;
    }

    for(; n > 0; n--) {
        puts(message);
        sleep(temp);
    }
/*
    When this program is ran it forks the processes into a parent and child
    where it is then ran the amount of times the user had told it to from 
    the command line arguments when running the program. When the fork is
    created due to the wait set on the parent process it waits for the 
    child to finish running before finishing its process.
*/
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