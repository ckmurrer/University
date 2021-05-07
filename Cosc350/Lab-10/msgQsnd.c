#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/sem.h>
#include <sys/msg.h>

typedef struct MSGBUF{
    long type;
    int one;
    int two;
} MsgBuffer;

int main(int argc, char *argv[]){
    // Sets key value to msgQsnd.c
    key_t key;
    if ((key = ftok("msgQsnd.c", 'B')) == -1){
        printf("ERROR: ftok() error!\n");
        exit(1);
    }

    // Creates the message queue with the key and the privileges rw-r--r-- (0644)
    int Qid;
    if ((Qid = msgget(key, 0644 | IPC_CREAT)) == -1){
        printf("ERROR: msgget() error!\n");
        exit(1);
    }

    MsgBuffer sendBuffer;
    sendBuffer.type = 1; // Set the message type to 1, must be > 0. Used by the receiving process for message selection
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
        // Converting the input into 2 integers
        if(sscanf(userInput, "%d%d", &sendBuffer.one, &sendBuffer.two) == 2){
            // Sending the MsgsendBuffer struct, with our 2 integers, to the message queue
            if (msgsnd(Qid, (MsgBuffer *)&sendBuffer, 2 * sizeof(int), 0) == -1){
                printf("ERROR: msgsnd() error!\n");
            }
        }
        sendBuffer.one = -10; // Clear buffer with custom value
        sendBuffer.two = -10; // Clear buffer with custom value
        printf("Enter two integers: \n");
    }
    return 0;
}