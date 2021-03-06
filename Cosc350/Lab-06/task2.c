#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

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
    int n,temp;
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
        break;
        default:
            message = "This is the parent";
            n = Np;
            temp = Tp;
        break;
    }

    for(; n > 0; n--) {
        puts(message);
        sleep(temp);
    }
    exit(0);
}