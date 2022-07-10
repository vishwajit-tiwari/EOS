/**
 * @file thread_attr.c
 * @author Vishwajit Tiwari (tvishwajit@cdac.in)
 * @brief A Thread Program Attributes (Detachable Thread attr)
 * @version 0.1
 * @date 2022-07-10
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>

pthread_t ptid;                     // Thread ID
pthread_attr_t attrD;               // Display Thread Attributes

// Pressure Thread
void * displayThread(void *data) {
    for(int i = 0; i < 5; ++i) {
        printf("In display thread %d\n", i+1);
    }
}

int main(int argc, char const *argv[])
{
    int thread_ret, thread_join_ret;

    pthread_attr_init(&attrD);          // Default Attributes
    // Set Attributes - Thread Detach State
    pthread_attr_setdetachstate(&attrD,PTHREAD_CREATE_DETACHED);
    
    printf("Before thread creation\n");

    /** int pthread_create(pthread_t *thread, const pthread_attr_t *attr, 
     *                          void *(*start_routine) (void *), void *arg);
     */

    // To create Thread
    thread_ret = pthread_create(&ptid, &attrD, displayThread, NULL);
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

    pthread_attr_destroy(&attrD);           // Destory Thread

    printf("Thread joined\n");

    return 0;
}