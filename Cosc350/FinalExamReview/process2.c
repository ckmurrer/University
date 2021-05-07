//process2.c
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
    int fd;

    key = ftok("process1.c", 'B');
    msqid = msgget(key, 0666);
    fd = open("HALF_DUPLEX", O_WRONLY);


	for(;;){
		msgrcv(msqid, (struct msgbuf*)&buf, sizeof(buf), 0,  0);
		printf("%s\n", buf.mtext);
		write(fd, "I got it", 8);
	}
	exit(0);
}
