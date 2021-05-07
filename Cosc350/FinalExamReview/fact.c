#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

void *factorial(void *num){
    printf("Factorial is running with user input: %d\n\n\n",(int)num);
    int fact=1;
    for(int i = 1; i<(int)num+1; i++){
        fact *= i;
    }
    return (void*)fact;
}

void *sum(void *num){
    printf("Sum is running with user input: %d\n",(int)num);    
    int sum = 0;
    for(int i = 1; i<(int)num+1;i++){
        sum += i;
    }
    return (void*)sum;
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

int main(int argc, char* argv[]){
    if(argc != 2){
        printf("Argument Error: Only input one integer\n");
        exit(1);
    }

    int number = str_to_int(argv[1]);

    pthread_t sumThread, factThread;
    int th;

    th = pthread_create(&sumThread,NULL,sum,(void*)number);
    if(th){
        printf("Thread Error: unable to create sum thread\n");
        exit(1);
    }
    void* numSum;
    pthread_join(sumThread,&numSum);

    th = pthread_create(&factThread,NULL,factorial,(void*)number);
    if(th){
        printf("Thread Error: unable to create factorial thread\n");
        exit(1);
    }
    void* numFactorial;
    pthread_join(factThread,&numFactorial);

    printf("Sum of user input %d is %d\n",number,(int)numSum);
    printf("Factorial of user input %d is %d\n",number,(int)numFactorial);

    pthread_exit(NULL);
    exit(0);
}