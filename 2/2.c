#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

int *ptr;

void *thread1Fun(void *arg){
    ptr = arg;
    printf("Value in thread1: %d\n", *ptr);
    pthread_exit(NULL);
}

void *thread2Fun(void *arg){
    *ptr += 5678;
    printf("Value in thread2: %d\n", *ptr);
    pthread_exit(NULL);
}

int main(){
    pthread_t thread1,thread2;
    int arg=1234;

    pthread_create(&thread1, NULL, thread1Fun, (void *)&arg);
    pthread_join(thread1, NULL);

    pthread_create(&thread2, NULL, thread2Fun, NULL);
    pthread_join(thread2, NULL);

    printf("Final value: %d\n", *ptr);

    return 0;
}
