/**
 * @file p2.c
 * @author Vishwajit Kumar Tiwari (tvishwajit@cdac.in)
 * @brief Process P2 calculates the occurence of letter/character 's' in the incoming data from P1
 * @version 0.1
 * @date 2022-09-13
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include<stdio.h>
#include<stdlib.h>
#include <fcntl.h>           /* For O_* constants */
#include <sys/stat.h>        /* For mode constants */
#include <mqueue.h>

#define MAX_SIZE 81920

// Global Variables
mqd_t mqd;
ssize_t mqrfd;
int count = 0;
struct mq_attr p2_attr;
unsigned char BuffP2[MAX_SIZE];


int main(int argc, char const *argv[])
{
    printf("Inside Process : P2 : %s() function\n", __FUNCTION__);

    // Setting attributes of Message Queue
    p2_attr.mq_curmsgs = 0;
    p2_attr.mq_flags = 0;
    p2_attr.mq_maxmsg = 4;
    p2_attr.mq_msgsize = 128;

    mqd = mq_open("/MessageQueue", O_RDONLY | O_CREAT, S_IRUSR | S_IWUSR, &p2_attr);

    if(mqd<0) {
        perror("error in mq_open ");
        exit(EXIT_FAILURE);
    }

    printf("Message Queue opened Successfully\n");

    mqrfd = mq_receive(mqd, BuffP2, sizeof(BuffP2), 0);

    if(mqrfd<0) {
        perror("error in mq_receive ");
        exit(EXIT_FAILURE);
    }

    printf("Message Received Successfully : bytes = %ld\n", mqrfd);

    for(int i=0; i<sizeof(BuffP2); i++)
    {
        if(BuffP2[i] == 's') {
            count++;
        }
    }

    printf("Process P2 : Number of letter 's' occured = %d\n", count);

    mq_close(mqd);

    return 0;

}

