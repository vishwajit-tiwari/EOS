/**
 * @file recursiveSolved.c
 * @author Vishwajit Kumar Tiwari (tvishwajit@cdac.in)
 * @brief Solution to Recursive Mutex
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
pthread_mutexattr_t mutex_count_attr;           // mutex attributes

// Increament Thread
void *incThread(void *data) {
    printf("Inside %s:\n\n", __FUNCTION__);
    while(1) {
        printf("Inc: Locking 1st time\n");
        pthread_mutex_lock(&mutex_conut);       // mutex 1st lock
        printf("Inc: Locking 2nd time\n");
        pthread_mutex_lock(&mutex_conut);       // mutex 2nd lock
        count++;
        printf("Inc Count = %d\n",count);
        pthread_mutex_unlock(&mutex_conut);     // mutex 1st unlock
        printf("Inc: Unlocked 1st time\n");
        pthread_mutex_unlock(&mutex_conut);     // mutex 2nd unlock
        printf("Inc: Unlocked 2nd time\n");
    }
}

// Decerement Thread
void * decThread(void * data) {
    printf("Inside %s:\n\n", __FUNCTION__);
    while (1)
    {
        printf("Dec: Locking\n");
        pthread_mutex_lock(&mutex_conut);       // mutex lock
        count--;
        printf("Dec Count = %d\n", count);
        pthread_mutex_unlock(&mutex_conut);     // mutex unlock
        printf("Dec: Unlocked\n");
    }
    
} 

int main(int argc, char const *argv[])
{
    pthread_t incId, decId;

    printf("Inside %s : Before Thread Creation\n", __FUNCTION__);

    // Configure the mutex attributes
    pthread_mutexattr_init(&mutex_count_attr);
    pthread_mutexattr_settype(&mutex_count_attr, PTHREAD_MUTEX_RECURSIVE);

    // Initialize the mutex
    pthread_mutex_init(&mutex_conut,&mutex_count_attr);      

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
