/**
 * @file racecondition.c
 * @author Vishwajit Tiwari (tvishwajit@cdac.in)
 * @brief Race-condition => Data Corruption (Shared Resource / Global Variables) 
 * @version 0.1
 * @date 2022-07-12
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

// Increament Thread
void * incThread(void * data) {
    printf("Inside %s:\n\n", __FUNCTION__);
    while(1) {
        printf("Inc Count = %d\n",count);
        count++;
    }
}

// Decerement Thread
void * decThread(void * data) {
    printf("Inside %s:\n\n", __FUNCTION__);
    while (1)
    {
        printf("Dec Count = %d\n", count);
        count--;
    }
    
}

int main(int argc, char const *argv[])
{
    printf("Inside %s : Before Thread Creation\n", __FUNCTION__);

    // Create Threads
    pthread_create(&incId,NULL,incThread,NULL);
    pthread_create(&decId,NULL,decThread,NULL);

    printf("Inside %s : After Thread Creation\n", __FUNCTION__);

    // Wating for newly creted thread to join
    pthread_join(incId,NULL);                   
    pthread_join(decId,NULL);

    printf("Inside %s : Thread Joined\n", __FUNCTION__);
    
    return 0;
}
