#include <sys/types.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <math.h>

void testScores(int* score){

   int i,input;
    printf("Enter up to 20 test scores, -1 will exit user input\n");
    for(i=0; i<20; i++){
        printf("Please enter a test score %d: ",i);
        scanf("%d",&input);
        while(input<-1){
            printf("Only input positive numbers");
            scanf("%d",&input);
        }
        if(input == -1){
            break;
        }else{
            score[i] = input;
        }
    }

    
    int j, k,temp;
// using insertion sort cause best O(n) worst/average is O(n^2)   
    for(int k =0; k<i;k++){
        temp = score[k];
        j = k-1;
        while(j >= 0 && score[j]>temp){
            score[j+1] = score[j];
            j = j-1;
        }
        score[j+1] = temp;
    }
    score[i] = -1;
    pthread_exit(NULL);
}

void avgmedScores(int* score){
    int i,sum = 0;
    for(i=0;score[i]!=-1;i++){
        sum += score[i];
    }
  
    if(i == 0){
        printf("There were no entries to calculate\n");
        pthread_exit(NULL);
    }
// calculates the average
    float average = (float) sum/i;
    float median;
// calculates the median    
    if(i%2 == 0){
        median = (score[(i-1)/2]+score[i/2])/2.0;
    }else{
        median = score[i/2];
    }
    printf("The average score  is: %2.2f\n",average);
    printf("The median score  is: %2.2f\n",median);

    pthread_exit(NULL);
}

void minmaxScores(int* score){
    int i, max=0;
    int min = score[0];
    for(i=0;score[i]!=-1;i++){
        max = score[i];
    }

    if(i == 0){
        printf("There were no entries to calculate max and min\n");
        pthread_exit(NULL);
    }

    printf("Max score is: %d\n",max);
    printf("Min score is: %d\n",min);
    pthread_exit(NULL);    
}

void clearBuffer(int* score){
    printf("Clearing Buffer...\n");
    printf("Buffer now contains\n");
    for(int i = 0; i < 20; i++){
        score[i] = 0;
        printf("%d",score[i]);
    }
    printf("\n");
    pthread_exit(NULL);
}

int main(int argc, char argv[]){
    pthread_t threads[4];// thread 0 = scores, thread 1 = avg/med scores, thread 2 = min/max scores, thread 3 = clear buffer
    int th;
    int* scores = malloc(20*sizeof(int));

    th = pthread_create(&threads[0],NULL,(void*)(int *)testScores,(void*)scores);
    if(th){
        printf("Thread Error: unable to create user input thread\n");
        exit(1);
    }
    pthread_join(threads[0],NULL);


    th = pthread_create(&threads[1],NULL,(void*)(int *)avgmedScores,(void*)scores);
    if(th){
        printf("Thread Error: unable to create user input thread\n");
        exit(1);
    }

    th = pthread_create(&threads[2],NULL,(void*)(int *)minmaxScores,(void*)scores);
    if(th){
        printf("Thread Error: unable to create user input thread\n");
        exit(1);
    }
    pthread_join(threads[1],NULL);
    pthread_join(threads[2],NULL);

    th = pthread_create(&threads[3],NULL,(void*)(int *)clearBuffer,(void*)scores);
    if(th){
        printf("Thread Error: unable to create user input thread\n");
        exit(1);
    }
    pthread_join(threads[3],NULL);

    pthread_exit(NULL);
    exit(0);

}