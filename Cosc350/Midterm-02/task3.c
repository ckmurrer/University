#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void *fun1(int* value){
    value[0] = value[0]+10;
    pthread_exit(NULL);
}

void *fun2(int* value){
    value[0]=value[0]+20;
    pthread_exit(NULL);
}

void *fun3(int* value){
    value[0]=value[0]+30;
    pthread_exit(NULL);
}

int str_to_int(char *input){ 
    int number = 0; 
    int position = 0; 
    while(input[position] != '\0'){ 
        number = (10 * number) + (input[position] - '0'); 
        position++; 
    } 
    return number; 
} 

int main(int args, char *argv[]){
    if(args != 2){
        printf("Invalid Input: too many or too little arguments passed\n");
        return 1;
    }
    printf("The user input is: %s\n", argv[1]);
    pthread_t threads[3];
    int temp;
    int* value  = malloc(1*sizeof(int));
    value[0] = str_to_int(argv[1]);

    temp = pthread_create(&threads[0],NULL,(void*)(int*)fun1,(void*)value);
    if(temp){
        printf("Thread Error: unable to create threads[0]\n");
        exit(1);
    }
    pthread_join(threads[0],NULL);

    temp = pthread_create(&threads[1],NULL,(void*)(int*)fun2,(void*)value);
    if(temp){
        printf("Thread Error: unable to create threads[0]\n");
        exit(1);
    }
    pthread_join(threads[1],NULL);

    temp = pthread_create(&threads[2],NULL,(void*)(int*)fun3,(void*)value);
    if(temp){
        printf("Thread Error: unable to create threads[0]\n");
        exit(1);
    }
    pthread_join(threads[2],NULL);

    printf("The third thread's calculation result is: %d\n",value[0]);
    
    free(value);
    return 0;
}