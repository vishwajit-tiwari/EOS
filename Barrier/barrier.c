/**
 * @file barrier.c
 * @author Vishwajit Kumar Tiwari (tvishwajit@cdac.in)
 * @brief When all components and threads are initialised then only process will start
 * @version 0.1
 * @date 2022-08-17
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>
#include<unistd.h>

// Global Variables
pthread_barrier_t init_barrier;


/*************************I2C_Thread*****************************/
void * i2c_thread(void * data) 
{
    printf("Inside %s\n", __FUNCTION__);
    printf("I2C init started\n");
    sleep(2);
    pthread_barrier_wait(&init_barrier);
    printf("I2C init completed\n");
}
/****************************************************************/


/*************************Ethernet_Thread************************/
void * ethernet_thread(void * data) 
{
    printf("Inside %s\n", __FUNCTION__);
    printf("Ethernet init started\n");
    sleep(6);
    pthread_barrier_wait(&init_barrier);
    printf("Ethernet init completed\n");
}
/****************************************************************/


/*************************UART_Thread****************************/
void * uart_thread(void * data) 
{
    printf("Inside %s\n", __FUNCTION__);
    printf("UART init started\n");
    sleep(3);
    pthread_barrier_wait(&init_barrier);
    printf("UART init completed\n");
}
/****************************************************************/


/*************************EEPROM_Thread**************************/
void * eeprom_thread(void * data) 
{
    printf("Inside %s\n", __FUNCTION__);
    printf("EEPROM init started\n");
    sleep(2);
    pthread_barrier_wait(&init_barrier);
    printf("EEPROM init completed\n");
}
/*****************************************************************/



/***************************Main Thread*******************************/
int main(int argc, char const *argv[])
{
    pthread_t i2c, ethernet, uart, eeprom;

    printf("Inside %s : Before thread creation\n", __FUNCTION__);

    // initialize barrier
    pthread_barrier_init(&init_barrier,NULL,4);

    // Creating Threads
    pthread_create(&i2c,NULL,i2c_thread,NULL);
    pthread_create(&ethernet,NULL,ethernet_thread,NULL);
    pthread_create(&uart,NULL,uart_thread,NULL);
    pthread_create(&eeprom,NULL,eeprom_thread,NULL);

    printf("Inside %s : After thread creation\n", __FUNCTION__);

    // Wating for newely created threads to join
    pthread_join(i2c,NULL);
    pthread_join(ethernet,NULL);
    pthread_join(uart,NULL);
    pthread_join(eeprom,NULL);

    
    return 0;
}
/*********************************************************************/