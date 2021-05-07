#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <pthread.h>

int bufferArray[10];
int pos = 0;

void consumer(){
    int i;
    
    while(1){
        int temp = bufferArray[pos - 1];

    	if(pos >= 0){
    		pos--;
    		bufferArray[pos] = 0;
    	}else{
    		printf("No value to remove\n");
        }

        printf("Consuming %d\n", temp);
    	for(i = 0; i < 10; i++){
    		printf("%d ", bufferArray[i]);
        }

    	printf("\n\n");
    	sleep(2);
    }
}

void producer(){
    int i;
    while(1){
        int item = rand() % 10;
        
    	if(pos < 10){
    		bufferArray[pos++] = item;
        }else{
    		printf("No space to insert. \n");
        }

        printf("Producing %d\n", item);
        for(i = 0; i < 10; i++){
            printf("%d ", bufferArray[i]);
        }
        printf("\n\n");
        sleep(1);
    }
}

int main(int argc, char* argv[]){
    pthread_t threads[2];
    pthread_create(&threads[0], NULL, (void*)producer, NULL);
    pthread_create(&threads[1], NULL, (void*)consumer, NULL);

    pthread_join(threads[0], NULL);
    pthread_join(threads[1], NULL);

    return 0;
}