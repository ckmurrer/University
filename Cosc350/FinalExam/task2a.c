#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/sem.h>
#include <unistd.h>
#include <sys/msg.h>
#include <string.h>

typedef struct MSGBUF{
    long type;
    int one;
    int two;
} MsgBuffer;

int main(int argc, char *argv[]){
    key_t key;
    if ((key = ftok(".", 'B')) == -1){
        printf("ERROR: ftok() error!\n");
        exit(1);
    }

    int Qid;
    if ((Qid = msgget(key, 0644 | IPC_CREAT)) == -1){
        printf("ERROR: msgget() error!\n");
        exit(1);
    }

    MsgBuffer sendBuffer;
    sendBuffer.type = 1; 
    char *userInput = (char *)calloc(256, sizeof(int));

    printf("Enter two integers: \n");

    while(1){
        fgets(userInput, 256, stdin);
        if (feof(stdin)) {
            sendBuffer.one = -1;
            sendBuffer.two = -1;
            if (msgsnd(Qid, (MsgBuffer *)&sendBuffer, 2 * sizeof(int), 0) == -1){
                printf("ERROR: msgsnd() error!\n");
            }
            printf("EOF terminating program.\n");
            if (msgctl(Qid, IPC_RMID, NULL) == -1){
                printf("ERROR: msgctl() error!\n");
                exit(1);
            }
            return 0;
        }
        if(sscanf(userInput, "%d%d", &sendBuffer.one, &sendBuffer.two) == 2){
            if (msgsnd(Qid, (MsgBuffer *)&sendBuffer, 2 * sizeof(int), 0) == -1){
                printf("ERROR: msgsnd() error!\n");
            }
        }else{
            // sends to task2b for invalid data print
            sendBuffer.one = -999;
            sendBuffer.two = -999;
            if (msgsnd(Qid, (MsgBuffer *)&sendBuffer, 2 * sizeof(int), 0) == -1){
                printf("ERROR: msgsnd() error!\n");
            }
        }
        sendBuffer.one = -10; 
        sendBuffer.two = -10;
        printf("Enter two integers: \n");
    }

    if(msgctl(Qid, IPC_RMID, NULL) == -1){
        perror("msgctl() error!");
        exit(1);
    }
    return 0;
}