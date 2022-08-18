/**
 * @file sender.c
 * @author Vishwajit Kumar Tiwari (tvishwajit@cdac.in)
 * @brief A Sender code for Message Queue
 * @version 0.1
 * @date 2022-08-18
 * 
 * @copyright Copyright (c) 2022
 *  
 */

#include<stdio.h>
#include<stdlib.h>
#include <fcntl.h>           /* For O_* constants */
#include <sys/stat.h>        /* For mode constants */
#include <mqueue.h>

// Global Variables
mqd_t cdacmq;
struct mq_attr cdacmq_attr;
int mqSend_ret;                 // return types of mq_send


int main(int argc, char const *argv[])
{
    printf("Inside %s: Sender Function\n", __FUNCTION__);

    // Setting attributes of Message Queue
    cdacmq_attr.mq_flags = 0;
    cdacmq_attr.mq_maxmsg = 4;
    cdacmq_attr.mq_msgsize = 128;
    cdacmq_attr.mq_curmsgs = 0;

    // Open Message Queue for Writing
    /* mqd_t mq_open(const char *name, int oflag, mode_t mode,
                     struct mq_attr *attr); */
    cdacmq = mq_open("/cdacmq", O_WRONLY | O_CREAT, S_IRUSR | S_IWUSR, &cdacmq_attr);
    if(cdacmq<0) {
        perror("Error opening Message Queue \n");
        exit(EXIT_FAILURE);
    }    

    // Send data to Message Queue
    mqSend_ret = mq_send(cdacmq, ">>>Hello from Sender Function<<<\n", 34, 0);
    if(mqSend_ret<0) {
        perror("Error while sending message \n");
        exit(EXIT_FAILURE);
    }
    else {
        printf("Message sent Sucessfully\n");
    }

    // Close Message Queue
    mq_close(cdacmq);

    return 0;
}
