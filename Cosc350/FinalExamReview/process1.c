//process1.c  
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <fcntl.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/msg.h>

struct my_msgbuf {
long mtype;
char mtext[200];
};

int main(){
	struct my_msgbuf buf;
	int msqid;
    key_t key;
    int temp;
    int fd;
    int n;
    char buffer[200];

    key = ftok("process1.c", 'B');
    msqid = msgget(key, 0666 | IPC_CREAT);

    temp = mkfifo("HALF_DUPLEX", 0666);
    fd = open("HALF_DUPLEX", O_RDONLY);

    while(fgets(buf.mtext, 200, stdin) || !feof(stdin)){
        msgsnd(msqid, (struct msgbuf*)&buf, sizeof(buf), 0);
        n = read(fd, buffer, 200);
        write(0, buffer, n);
        printf("\n");
    }

    msgctl(msqid, IPC_RMID, NULL);
    exit(0);
}
