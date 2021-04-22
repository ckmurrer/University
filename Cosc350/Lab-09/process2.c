#include <stdio.h>
#include <stdlib.h>
#include <sys/shm.h>
#include <errno.h>
#include "header.h"

int main(int argc, char *argv[]){
    int shmid, sum;
    key_t key;
    struct Memory *shm;
    key = ftok(".", 'x'); 

    if ((shmid = shmget(key, sizeof(struct Memory), 0)) <0){
        perror("shmget error \n");
        exit (1);
    }

    shm = (struct Memory *) shmat(shmid, NULL, 0);
    if ((long)shm == -1){
        perror("shmat error \n");
        exit (1);
    }

    while (shm->gostop == GO){
        while (shm->status != FILLED){
            if (shm->gostop == STOP)
                break;
            ;
        }
        if(shm->data.finish == STOP){
            printf("\nProcess1.c exited by EOF and stopped sending data\n");
            break;
        }else{
            sum = shm->data.numberOne + shm->data.numberTwo;
            printf ("Integer One: %d \n", shm->data.numberOne);
            printf ("Integer Two: %d\n", shm->data.numberTwo);
            printf ("Sum of Integers: %d\n",sum);
            shm->status = TAKEN;
        }
    }
    shmdt((void *) shm);
    return 0;
}
