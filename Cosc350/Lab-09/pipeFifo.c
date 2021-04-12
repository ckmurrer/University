#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <fcntl.h>

#define FIFO_TASK "/tmp/task4_fifo"
#define READ_END 0
#define WRITE_END 1

int main(){
    int data_processed;
    const char some_data[] = "123";
    char* buffer = calloc(3,sizeof(char));
    memset(buffer, '\0', 3);
    int makefifo = mkfifo(FIFO_TASK,0777);
    int fileOpen = open(FIFO_TASK, O_RDWR);

    data_processed = write(fileOpen, some_data, strlen(some_data));
    printf("Wrote %d bytes\n", data_processed);
    data_processed = read(fileOpen, buffer, 3);
    printf("Read %d bytes: %s\n", data_processed, buffer);
    
    exit(EXIT_SUCCESS);
}