/**
 * @file p1.c
 * @author Vishwajit Kumar Tiwari (tvishwajit@cdac.in)
 * @brief Process P1 opens a file "/usr/include/stdio.h" read data from file and sends it to P2
 * @version 0.1
 * @date 2022-09-13
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>
#include<mqueue.h>

// Global Buffer
#define MAXBUFF 81920
unsigned char BuffP1[MAXBUFF];

// Global Variables
mqd_t mqDescriptor;
struct mq_attr p1_attr;
int mqSendFd;
unsigned int priority = 0;

int openFd;
ssize_t retREAD;


int main(int argc, char const *argv[])
{
    printf("Inside Process : P1 : %s() function\n", __FUNCTION__);

    // Setting attributes of message Queue
    p1_attr.mq_curmsgs = 0;
    p1_attr.mq_flags = 0;
    p1_attr.mq_maxmsg = 4;
    p1_attr.mq_msgsize = MAXBUFF;

    /********************************Open Message Queue**************************************/
    mqDescriptor = mq_open("/MessageQueue", O_WRONLY | O_CREAT, S_IRUSR | S_IWUSR, &p1_attr);

    if(mqDescriptor<0) {
        perror("error in message queue open : ");
        exit(EXIT_FAILURE);
    }

    printf("Message Queue opened successfully\n");

    /*Open Specified File*/
    openFd = open("/usr/include/stdio.h", O_RDONLY);
    
    if(openFd < 0) {
        perror("error in open sys call : ");
        exit(EXIT_FAILURE);
    }

    printf("File open successfully\n");
    
    /**Read data from File descriptor**/
    retREAD = read(openFd, BuffP1, sizeof(BuffP1));

    if(retREAD<0) {
        perror("error in read sys call : ");
        exit(EXIT_FAILURE);
    }
    else 
    {
        printf("Number of bytes read in Process : P1 : %ld\n", retREAD);

        /*Send Data to P2*/
        mqSendFd = mq_send(mqDescriptor, (const char *)BuffP1, 128, priority);

        if(mqSendFd<0) {
            perror("error in mq_send : ");
            exit(EXIT_FAILURE);
        }

        printf("Message sent successfully : data left = %d\n", mqSendFd);
        
    }

    mq_close(mqDescriptor);

    return 0;
}
