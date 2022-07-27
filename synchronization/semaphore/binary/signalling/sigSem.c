/**
 * @file sigSem.c
 * @author Vishwajit Tiwari (tvishwajit@cdac.in)
 * @brief A Signalling Semaphore (Solve Race Condition / Shared Resource)
 * @version 0.1
 * @date 2022-07-27
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<semaphore.h>

/****************Global Variables**********************/
pthread_t inputID, procID;
int num1 = 0,num2 = 0, sum = 0;
sem_t s1, s2;

/*********************Input Thread**************************/
/**
 * @brief Processing Thread
 * void *(*start_routine) (void *)
 * @param data 
 * @return void* 
 */
void * inputThread(void *data) 
{
    printf("\nInside %s:\n", __FUNCTION__);
    while(1) 
    {
        sem_wait(&s1);          // sem_wait() decrements (locks) the semaphore s1 value i.e. s1 = 0
        printf("Enter two numbers: ");
        scanf("%d",&num1);
        scanf("%d",&num2);
        sem_post(&s2);          // sem_post() increments (unlocks) the semaphore s2 value i.e s2 = 1
    }
}
/************************************************************/

/*********************Processing Thread**********************/
/**
 * @brief Processing Thread
 * void *(*start_routine) (void *)
 * @param data 
 * @return void* 
 */
void * procThread(void *data) 
{
    printf("\nInside %s:\n", __FUNCTION__);
    while(1) 
    {
        sem_wait(&s2);          // sem_wait() decrements (locks) the semaphore s2 value i.e. s2 = 0
        sum = num1+num2;
        printf("Sum = %d\n",sum);
        sem_post(&s1);          // sem_post() increments (unlocks) the semaphore s1 value i.e. s1 = 1
    }
}
/**************************************************************/


/******************************************Main Thread***********&***********************************/
int main(int argc, char const *argv[])
{
    printf("Inside %s : Before Thread Creation\n", __FUNCTION__);
    
    /**
     * @brief Initialing Semaphore
     * sem_init(sem_t *__sem, int __psthread, unsigned int __value);
     * If pshared == 0, then the semaphore is shared between the threads of a process,
     * and should be a global variable, or a variable allocated dynamically on the heap.
     * If psthread != 0, then the semaphore is shared between processes, 
     * and should be located in a region of shared memory (see shm_open(3),mmap(2), and shmget(2)).
     */
    sem_init(&s1,0,1);          
    sem_init(&s2,0,0);

    /**
     * @brief Creating Threads
     * int pthread_create(pthread_t *thread, const pthread_attr_t *attr,
     *                          void *(*start_routine) (void *), void *arg);
     * 1. Thread ID
     * 2. Thread Attributes
     * 3. Name of Thread
     * 4. Arguments to Thread
     */
    pthread_create(&inputID,NULL,inputThread,NULL);
    pthread_create(&procID,NULL,procThread,NULL);

    printf("Inside %s : After Thread Creation\n", __FUNCTION__);

    /**
     * @brief Wating for newly created thread to join
     * extern int pthread_join (pthread_t __th, void **__thread_return);
     */
    pthread_join(inputID,NULL);
    pthread_join(procID,NULL);

    /**
     * @brief Destroy Semaphore after use
     * int sem_destroy(sem_t *__sem)
     */
    sem_destroy(&s1);
    sem_destroy(&s2);

    printf("Inside %s : Thread Joined\n", __FUNCTION__);

    return 0;
}
/****************************************End of Main Thread*********************************************/