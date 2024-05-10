#include <stdio.h>
#include <pthread.h>

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
int sharedData = 0;

void *threadFunc1(void *arg){
    pthread_mutex_lock(&mutex);
    sharedData+=3;
    printf("Thread 1: sharedData = %d\n", sharedData);
    pthread_mutex_unlock(&mutex);

    pthread_exit(NULL);
}

void *threadFunc2(void *arg){
    pthread_mutex_lock(&mutex);
    sharedData*=2;
    printf("Thread 2: sharedData = %d\n", sharedData);
    pthread_mutex_unlock(&mutex);

    pthread_exit(NULL);
}

int main()
{
    pthread_t thread1, thread2;

    pthread_create(&thread1, NULL, threadFunc1, NULL);
    pthread_create(&thread2, NULL, threadFunc2, NULL);

    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    printf("Main: sharedData = %d\n", sharedData);

    return 0;
}
