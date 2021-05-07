#include <stdio.h>
#include <stdlib.h>
#include <sys/shm.h>
#include <errno.h>

#define NOT_READY -1
#define FILLED 0 
#define TAKEN 1 
#define GO 2
#define STOP 3

struct userInput {
    int numberOne;
    int numberTwo;
    int finish;
};

struct Memory {
    int status;
    int gostop;
    struct userInput data;
};

int main(int argc, char *argv[]){
    int sharedMemID, total;
    key_t key;
    struct Memory *sharedMem;
    key = ftok(".", 'B'); 

    if ((sharedMemID = shmget(key, sizeof(struct Memory), 0)) <0){
        perror("shmget error \n");
        exit (1);
    }

    sharedMem = (struct Memory *) shmat(sharedMemID, NULL, 0);
    if ((long)sharedMem == -1){
        perror("shmat error \n");
        exit (1);
    }

    while (sharedMem->gostop == GO){
        while (sharedMem->status != FILLED){
            if (sharedMem->gostop == STOP)
                break;
            ;
        }
        if(sharedMem->data.finish == STOP){
            printf("\ntask2a exited by EOF and stopped sending data\n");
            break;
        }else{
            total = sharedMem->data.numberOne + sharedMem->data.numberTwo;
            printf ("Integer One: %d \n", sharedMem->data.numberOne);
            printf ("Integer Two: %d\n", sharedMem->data.numberTwo);
            printf ("total of passed Integers: %d\n",total);
            sharedMem->status = TAKEN;
        }
    }
    shmdt((void *) sharedMem);
    return 0;
}