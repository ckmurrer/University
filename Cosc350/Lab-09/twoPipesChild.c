#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
int main(int argc, char *argv[]){
    int data_processed, data_write;
    int readFileDes, writeFileDes;

    char buffer[BUFSIZ + 1];
    memset(buffer, '\0', sizeof(buffer));

    sscanf(argv[1], "%d", &readFileDes);
    sscanf(argv[2], "%d", &writeFileDes);

    data_processed = read(readFileDes, buffer, BUFSIZ);
    data_write = write(writeFileDes,"Hi mom", 6);

    printf("Child (%d) recieved the message %s made of %d bytes. \n", getpid(), buffer, data_processed);
    printf("Child (%d) sent %d bytes to the parent. \n", getpid(), data_write);

    exit(EXIT_SUCCESS);
}