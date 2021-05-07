#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
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
		printf("ftok() Error.\n");
		exit(1);
	}

	// Creates the message queue with the key and the privileges rw-r--r-- (0644)
	int Qid;
	if ((Qid = msgget(key, 0644 | IPC_CREAT)) == -1){
		printf("msgget() Error.\n");
		exit(1);
	}

	MsgBuffer recieveBuffer;
	while (1){
		// Reads the message from the buffer and store into MsgBuffer object
		if (msgrcv(Qid, (MsgBuffer *)&recieveBuffer, 2 * sizeof(int), 0, 0) == -1)
		{
			printf("Termination sent from msgQsnd.\n");
			msgctl(Qid, IPC_RMID, NULL);
			exit(0);
		}
		if(recieveBuffer.one != -1 && recieveBuffer.two != -1){
			printf("The sum of integers are %d \n", recieveBuffer.one + recieveBuffer.two);
		}
	}
	return 0;
}