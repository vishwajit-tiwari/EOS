/**
 * @file receiver.c
 * @author Vishwajit Kumar Tiwari (tvishwajit@cdac.in)
 * @brief A Receiver code for Message Queue
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
char buff[128];
int msg_priority;
ssize_t mqReceive_ret;          // Return types of mq_receive


int main(int argc, char const *argv[])
{
    printf("Inside %s: Receiver Function\n", __FUNCTION__);

    // Setting attributes of Message Queue
    cdacmq_attr.mq_flags = 0;
    cdacmq_attr.mq_maxmsg = 4;
    cdacmq_attr.mq_msgsize = 128;
    cdacmq_attr.mq_curmsgs = 0;

    // Open Message Queue for Reading
    /* mqd_t mq_open(const char *name, int oflag, mode_t mode,
                     struct mq_attr *attr); */
    cdacmq = mq_open("/cdacmq", O_RDONLY | O_CREAT, S_IRUSR | S_IWUSR, &cdacmq_attr);
    if(cdacmq<0) {
        perror("Error opening Message Queue \n");
        exit(EXIT_FAILURE);
    }    

    // Receive data from Message Queue
    mqReceive_ret = mq_receive(cdacmq, buff, 128, &msg_priority);
    if(mqReceive_ret == -1) {
        perror("Error while receiving \n");
        exit(EXIT_FAILURE);
    }

    // Display/Print the Message Received
    printf("Received Msg: %s\nMsg Priority:%d\n", buff, msg_priority);
    printf("Number of bytes in the Received Message: %ld\n", mqReceive_ret);

    // Close Message Queue
    mq_close(cdacmq);

    return 0;
}
