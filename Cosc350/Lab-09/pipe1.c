#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define READ_END 0
#define WRITE_END 1

int main(){
    int data_processed;
    int file_pipes[2];
    const char some_data[] = "123";
    char* buffer = calloc(3,sizeof(char));
    memset(buffer, '\0', 3);
    if (pipe(file_pipes) == 0) {
        data_processed = write(file_pipes[WRITE_END], some_data, strlen(some_data));
        printf("Wrote %d bytes\n", data_processed);
        data_processed = read(file_pipes[READ_END], buffer, 3);
        printf("Read %d bytes: %s\n", data_processed, buffer);
        exit(EXIT_SUCCESS);
    }
    exit(EXIT_FAILURE);
}