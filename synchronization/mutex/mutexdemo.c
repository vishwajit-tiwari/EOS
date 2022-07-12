/**
 * @file mutex.c
 * @author Vishwajit Tiwari (tvishwajit@cdac.in)
 * @brief Mutex to solve Race-Condition (Synchronization)
 * @version 0.1
 * @date 2022-07-13
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>

// Global Variable
int count = 0;
pthread_t incId, decId;

// Mutex
pthread_mutex_t mutex_conut;

// Increament Thread
void * incThread(void * data) {
    printf("Inside %s:\n\n", __FUNCTION__);
    while(1) {
        pthread_mutex_lock(&mutex_conut);       // mutex lock
        count++;
        printf("Inc Count = %d\n",count);
        pthread_mutex_unlock(&mutex_conut);     // mutex unlock
    }
}

// Decerement Thread
void * decThread(void * data) {
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
    printf("Inside %s : Before Thread Creation\n", __FUNCTION__);

    // mutex initialization
    pthread_mutex_init(&mutex_conut,NULL);      

    // Create Threads
    pthread_create(&incId,NULL,incThread,NULL);
    pthread_create(&decId,NULL,decThread,NULL);

    printf("Inside %s : After Thread Creation\n", __FUNCTION__);

    // Wating for newly creted thread to join
    pthread_join(incId,NULL);                   
    pthread_join(decId,NULL);

     // destory mutex after use
    pthread_mutex_destroy(&mutex_conut);       

    printf("Inside %s : Thread Joined\n", __FUNCTION__);
    
    return 0;
}
