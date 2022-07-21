/**
 * @file mutualExSemaphore.c
 * @author Vishwajit Kuamr Tiwari (tvishwajit@cdac.in)
 * @brief A Mutual Exclution Semaphore  (Solve Raceconditiion / Shared Resource)
 * @version 0.1
 * @date 2022-07-21
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<semaphore.h>

/**************Global Variable / Shared Resource*****************/
int count = 0;
sem_t sem_count;   // Semaphore count
pthread_t incID,decID;

/**********************Increment Thread**************************/
void* incThread(void* data) {
    printf("Inside %s:\n\n", __FUNCTION__);
    while (1)
    {
        sem_wait(&sem_count);       // Acquiring Semaphore
        count++;
        printf("Inc count = %d\n", count);
        sem_post(&sem_count);       // Releasing Semaphore
    }
}

/**********************Decrement Thread**************************/
void* decThread(void *data) {
    printf("Inside %s:\n\n", __FUNCTION__);
    while (1)
    {
        sem_wait(&sem_count);       // Acquiring Semaphore
        count--;
        printf("Dec count = %d\n", count);
        sem_post(&sem_count);       // Releasing Semaphore
    }
    
}

/***************************Main Thread***************************/
int main(int argc, char const *argv[])
{
    printf("Inside %s: Before Thread Creation\n", __FUNCTION__);

    // Initializing Semaphore
    sem_init(&sem_count,0,1);

    // Creating Threads
    pthread_create(&incID,NULL,incThread,NULL);
    pthread_create(&decID,NULL,decThread,NULL);

    printf("Inside %s: After Thread Creation\n", __FUNCTION__);

    // Wating for newly created threads to Join
    pthread_join(incID,NULL);
    pthread_join(decID,NULL);

    // Destroy Semaphore after use
    sem_destroy(&sem_count);

    printf("Inside %s: Thread Joined\n", __FUNCTION__);

    return 0;
}
