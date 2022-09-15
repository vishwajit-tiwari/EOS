/**
 * @file p1.c
 * @author Vishwajit Kumar Tiwari (tvishwajit@cdac.in)
 * @brief A recevier code for FIFO_API
 * @version 0.1
 * @date 2022-09-15
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include<stdio.h>
#include<stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include<fcntl.h>
#include<unistd.h>

#define MAX_SIZE 81920

// Global Varialbes
unsigned char Buffp2[MAX_SIZE];
int count = 0;


int main(int argc, char const *argv[])
{
    int retFIFO, openfifoFd;
    ssize_t retRead, retWrite;

    printf("Inside Process : P2 : %s() function\n", __FUNCTION__);

    // Create a named PIPE called FIFO
    // retFIFO = mkfifo("myFIFO", S_IRUSR | S_IWUSR);
    // if(retFIFO<0) {
    //     perror("error in mkfifo ");
    //     exit(EXIT_FAILURE);
    // }
    // printf("FIFO created successfully\n");

    // open specified file
    openfifoFd = open("myFIFO", O_RDONLY);
    if(openfifoFd<0) {
        perror("error in open ");
        exit(EXIT_FAILURE);
    }

    printf("FIFO open successfully\n");

    // read data from specified file using file descriptor
    retRead = read(openfifoFd, Buffp2, sizeof(Buffp2));
    if(retRead<0) {
        perror("error in read sys call ");
        exit(EXIT_FAILURE);
    }

    printf("Sucessfully read %ld bytes\n", retRead);

    // Find out occurence of 's' in incoming data from p1
    for(int i=0; i<sizeof(Buffp2); i++) {
        if(Buffp2[i] == 's') {
            count++;
        }
    }

    printf("In Process : P2 : Letter/Character 's' occured %d times\n", count);

    close(openfifoFd);
    
    //To remove Named FIFO
    unlink("myFIFO");

    return 0;
}
