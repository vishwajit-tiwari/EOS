/**
 * @file recursiveProblem.c
 * @author Vishwajit Kumar Tiwari (tvishwajit@cdac.in)
 * @brief Problem of Recursive Mutex
 * @version 0.1
 * @date 2022-08-04
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>

// Global Variable
int count = 0;

// Mutex
pthread_mutex_t mutex_conut;

// Increament Thread
void *incThread(void * data) {
    printf("Inside %s:\n\n", __FUNCTION__);
    while(1) {
        printf("Inc: Locking 1st time\n");
        pthread_mutex_lock(&mutex_conut);       // mutex lock
        printf("Inc: Locking 2nd time\n");
        pthread_mutex_lock(&mutex_conut);       // mutex lock
        count++;
        printf("Inc Count = %d\n",count);
        pthread_mutex_unlock(&mutex_conut);     // mutex unlock
        printf("Inc: Unlocked 1st time\n");
        pthread_mutex_unlock(&mutex_conut);     // mutex unlock
        printf("Inc: Unlocked 2nd time\n");
    }
}

// Decerement Thread
void *decThread(void * data) {
    printf("Inside %s:\n\n", __FUNCTION__);
    while (1)
    {
        pthread_mutex_lock(&mutex_conut);       // mutex lock
        count--;
        printf("Dec Count = %d\n", count);
        pthread_mutex_unlock(&mutex_conut);     // mutex unlock
    }
    
}

int main(int argc, char const *argv[])
{
    pthread_t incId, decId;

    printf("Inside %s : Before Thread Creation\n", __FUNCTION__);

    // mutex initialization
    pthread_mutex_init(&mutex_conut,NULL);      

    // Create Threads
    pthread_create(&decId,NULL,decThread,NULL);
    pthread_create(&incId,NULL,incThread,NULL);

    printf("Inside %s : After Thread Creation\n", __FUNCTION__);

    // Wating for newly creted thread to join  
    pthread_join(decId,NULL);                 
    pthread_join(incId,NULL);

     // destory mutex after use
    pthread_mutex_destroy(&mutex_conut);       

    printf("Inside %s : Thread Joined\n", __FUNCTION__);
    
    return 0;
}
