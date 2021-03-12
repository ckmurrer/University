// run like ./task1 0<foo 1>clone
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define BUFFER_SIZE 1

int main(int argc, char* argv[]){

    char buffer[BUFFER_SIZE];
    int temp;

    while((temp = read(0, &buffer, BUFFER_SIZE)) > 0){
        if(write(1,&buffer,temp) != temp){
            printf("Write Error\n");
            exit(1);
        }
    }
    if(temp < 0){
        printf("Read Error\n");
    }
    exit(0);
}