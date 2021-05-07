#include <string.h>
#include <stdlib.h>
#include <sys/sem.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/ipc.h>
#include <sys/types.h>

#define SIZE 10
typedef int semaphore;
semaphore mutex = 0;
semaphore empty = 2;
semaphore full = 1;

union semun {
    int val;
    struct semid_ds *buf;
    unsigned short *array;
};

void up(int i, int semid) {
    struct sembuf up = {i, 1, 0};
    semop(semid, &up, 1);
}

void down(int i, int semid) {
    struct sembuf down = {i, -1, 0};
    semop(semid, &down, 1);
}

int main() {
    union semun sema;
    key_t key = ftok(".", 'K');
    int semid = semget(key, 1, 0666 | IPC_CREAT);

    sema.val = 1;
    if(semctl(semid, 0, SETVAL, sema));
    fork();

    if (semctl(semid, 0, IPC_RMID, sema) == -1){
        perror("semctl() Error");
        exit(1);
    }
    return 0; 
}