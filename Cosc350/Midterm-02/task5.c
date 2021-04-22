#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

void Bye(void *arg){
    pthread_t tid = (pthread_t) arg;
    printf("Bye!\n");
    pthread_exit(NULL);
}

void *Thread2(){
    pthread_t tid = pthread_self();
    pthread_cleanup_push(Bye, (void *)tid);
    while(1){
        printf("This is the second thread!\n");
        pthread_testcancel();
        sleep(1);
    }
    pthread_cleanup_pop(0);
}

void *Thread1(void *arg){
    int count, rc;
    pthread_t tid = (pthread_t)arg;
    printf("Entered the first thread\n");
    for(count=0; count<10; count++){
        printf("This is the first thread running %d times\n", count);
        sleep(1);
    }
    if(count == 9){
        pthread_cleanup_push(Bye, (void *)tid);
        while(1){
            pthread_testcancel();
            sleep(1);
        }
        pthread_cleanup_pop(0);
    }
    pthread_exit(NULL);
}

int main(){

    //Creating our threads
    pthread_t t1;
    pthread_t t2;

    //threads for calculating the sum/factorial
    int thr1_pt = pthread_create(&t2, NULL, Thread2, NULL);
    int thr2_pt = pthread_create(&t1, NULL, Thread1, &t2);

    if(thr1_pt != 0 || thr2_pt != 0){
        printf("Threads did not create successfully\n");
        return 0;
    }

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    return 0;

}