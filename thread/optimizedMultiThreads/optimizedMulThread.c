/**
 * @file optimizedMulThread.c
 * @author Vishwajit Tiwari (tvishwajit@cdac.in)
 * @brief Optimized Multi-Threading Program
 * @version 0.1
 * @date 2022-07-11
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>

/*Global Variables*/
pthread_t uart1_tid;                        // Thread id 1
pthread_t uart2_tid;                        // Thread id 2

// UART_init
void * uartInit(void *data) 
{
    printf("In %s : Baudrate : %d\n", __FUNCTION__, *(int*)data);
}

int main(int argc, char const *argv[])
{
    int baudrate1, baudrate2;               // Baudrates
    int pthread1_ret, pthread2_ret;         // Return type of pthread_create

    printf("In %s : Before Thread Creation\n", __FUNCTION__);
    baudrate1 = 9600;

    //Create Thread 1
    pthread1_ret = pthread_create(&uart1_tid,NULL,uartInit,&baudrate1);
    
    if(pthread1_ret != 0) {
        perror("Error!!! creating thread1");
        exit(EXIT_FAILURE);
    }
    
    baudrate2 = 115200;

    //Create Thread 2
    pthread2_ret = pthread_create(&uart2_tid,NULL,uartInit,&baudrate2);

    if(pthread2_ret != 0) {
        perror("Error !!! creating thread2");
        exit(EXIT_FAILURE);
    }

    printf("In %s : After Thread Creation\n", __FUNCTION__);

    pthread_join(uart1_tid,NULL);           // Wating for newely creted threads to join
    pthread_join(uart2_tid,NULL);

    printf("In %s : Threads Joined\n", __FUNCTION__);

    return 0;
}
