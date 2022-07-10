
#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>

pthread_t ptid;                     // Thread ID

// Pressure Thread
void * pressureThread(void *data) {
    for(int i = 0; i < 5; ++i) {
        printf("In pressure thread %d\n", i+1);
    }
}

int main(int argc, char const *argv[])
{
    int thread_ret, thread_join_ret;
    
    printf("Before thread creation\n");

    // int pthread_create(pthread_t *thread, const pthread_attr_t *attr,
    //                       void *(*start_routine) (void *), void *arg);

    // To create Thread
    thread_ret = pthread_create(&ptid, NULL, pressureThread, NULL);
    if(thread_ret != 0) {
        perror("Error creting thread\n");
        exit(EXIT_FAILURE);
    }

    printf("After thread creation\n");

    // main thread will wait for pressure thread to complete its execution
    thread_join_ret = pthread_join(ptid, NULL);
    if(thread_join_ret != 0) {
        perror("Error joining thread\n");
        exit(EXIT_FAILURE);
    }

    printf("Thread joined\n");

    return 0;
}