#include <unistd.h>
#include <sys/sem.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <signal.h>

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

void down(int i, int semid) {
    struct sembuf down = {i, -1, 0};
    semop(semid, &down, 1);
}

void up(int i, int semid) {
    struct sembuf up = {i, 1, 0};
    semop(semid, &up, 1);
}

void terminate(int sig){
    if(sig == SIGUSR1){
        printf("parent terminated by child\n");
        exit(0);
    }else if(sig == SIGUSR2){
        printf("i am child and must leave\n");
        exit(0);
    }
}

int main() {
    union semun sema;
    key_t key = ftok(".", 'K');
    int semid = semget(key, 1, 0);

    pid_t pid = fork();
    int count = 0;
    if(pid == 0) { // Child process
        while(1){
            if(count == 100){
                kill(getppid(),SIGUSR1);
                kill(pid, SIGUSR2);
            }
            signal(SIGUSR2, terminate);

            down(empty, semid);
            down(mutex, semid);

            printf("Child is in critical section %d\n",count);

            up(mutex, semid);
            up(full, semid);

            count++;
            sleep(2);
        }
    } else { // parent process
        while(1) {
            signal(SIGUSR1, terminate);  

            down(empty, semid);
            down(mutex, semid);

            printf("Parent is in critical section\n");

            up(mutex, semid);
            up(full, semid);

            sleep(1);
        }
    } 
    // Removes the semaphores
    if (semctl(semid, 0, IPC_RMID, sema) == -1){
        perror("semctl() Error");
        exit(1);
    }
    return 0;
}