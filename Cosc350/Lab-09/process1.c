#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/shm.h>
#include <errno.h>
#include "header.h"

int main(int argc, char *argv[]){
    int shmid;
    key_t key;
    struct Memory *shm;
    char* numbers = malloc(256*sizeof(int));
    key = ftok(".", 'x'); //get key value
    if ((shmid = shmget(key, sizeof(struct Memory), 0)) <0){
        perror("shmget error \n");
        exit (1);
    }
    shm = (struct Memory *) shmat(shmid, NULL, 0);
    if ((long)shm == -1){
        perror("shmat error \n");
        exit (1);
    }
    
    shm->gostop = GO;
    shm->status = NOT_READY;

    while(1){
        printf("Enter Two Integers To Get The Sum.\n");
        fgets(numbers,256,stdin);
        if(feof(stdin)){
            printf("\nExited by EOF\n");
            shm->data.finish = STOP;
            break;
        }
        if(sscanf(numbers,"%d%d",&shm->data.numberOne,&shm->data.numberTwo) == 2){
            shm->status = FILLED;
        }else{
            printf("Invalid Input Integers Only\n");
            continue;
        }

        while (shm->status != TAKEN)
            ;
    }
    shm->gostop = STOP;
    shmdt((void *) shm);
    return 0;
}