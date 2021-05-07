#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/sem.h>
#include <sys/shm.h>
#include <sys/msg.h>

#define NOT_READY -1
#define FILLED 0 
#define TAKEN 1 
#define GO 2
#define STOP 3

typedef struct MSGBUF{
	int two;
	long type;
	int one;
} MsgBuffer;

struct userInput {
    int finish;
    int numberOne;
    int numberTwo;
};

struct Memory {
    int gostop;
    int status;
    struct userInput data;
};

int main(int argc, char *argv[]){
// recieve from message queue
	key_t key;
	if ((key = ftok(".", 'B')) == -1){
		printf("ftok() Error.\n");
		exit(1);
	}

	int Qid;
	if ((Qid = msgget(key, 0644 | IPC_CREAT)) == -1){
		printf("msgget() Error.\n");
		exit(1);
	}

// create shared memory
	int sharedMemID;
	struct Memory *sharedMem;
	if ((sharedMemID = shmget(key, sizeof(struct Memory), IPC_CREAT | 0666)) <0){
        perror("Error: Unable to do shmget\n");
        exit (1);
    }

    sharedMem = (struct Memory *) shmat(sharedMemID, NULL, 0);
    if ((long)sharedMem == -1){
        perror("Error: Unable to do shmat\n");
        exit (1);
    }

    sharedMem->status = NOT_READY;
    sharedMem->gostop = GO;

	MsgBuffer recieveBuffer;
	while (1){
		if (msgrcv(Qid, (MsgBuffer *)&recieveBuffer, 2 * sizeof(int), 0, 0) == -1){
			printf("EOF termination sent from task2a.\n");

			sharedMem->data.finish = STOP;
			sharedMem->gostop = STOP;

			msgctl(Qid, IPC_RMID, NULL);
			shmctl(sharedMemID, IPC_RMID, NULL);
			exit(0);
		}
		if(recieveBuffer.one != -1 && recieveBuffer.two != -1){
            if(recieveBuffer.one == -999 && recieveBuffer.two == -999){
                printf("Invalid User Input\n");
            }else{
				sharedMem->data.numberOne = recieveBuffer.one;
				sharedMem->data.numberTwo = recieveBuffer.two;
				sharedMem->status = FILLED;
            }
        }
	}
	return 0;
}