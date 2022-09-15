/**
 * @file p1.c
 * @author Vishwajit Kumar Tiwari (tvishwajit@cdac.in)
 * @brief A sender code for FIFO_API
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
unsigned char Buffp1[MAX_SIZE];


int main(int argc, char const *argv[])
{
    int retFIFO, openfd, openFIFO;
    ssize_t retRead, retWrite;

    printf("Inside Process : P1 : %s() function\n", __FUNCTION__);

    // Create a named PIPE called FIFO
    retFIFO = mkfifo("myFIFO", S_IRUSR | S_IWUSR);
    if(retFIFO<0) {
        perror("error in mkfifo ");
        exit(EXIT_FAILURE);
    }

    printf("FIFO created successfully\n");

    // Open newely created FIFO
    openFIFO = open("myFIFO", O_WRONLY);
    if(openFIFO == -1) {
        perror("Error opening named fifo\n");
        exit(EXIT_FAILURE);
    }

    printf("FIFO open successfully\n");

    // open specified file
    openfd = open("/usr/include/stdio.h", O_RDONLY);
    if(openfd<0) {
        perror("error in open ");
        exit(EXIT_FAILURE);
    }

    printf("File open successfully\n");

    // read data from specified file using file descriptor
    retRead = read(openfd, Buffp1, sizeof(Buffp1));
    if(retRead<0) {
        perror("error in read sys call ");
        exit(EXIT_FAILURE);
    }

    printf("Sucessfully read %ld bytes\n", retRead);

    // Send data to Process P2 using FIFO
    retWrite = write(openFIFO, Buffp1, sizeof(Buffp1));
    if(retWrite<0) {
        perror("error in write sys call ");
        exit(EXIT_FAILURE);
    }

    printf("Successfully written : %ld bytes\n", retWrite);

    close(openfd);
    close(openFIFO);

    //To remove Named FIFO
    unlink("myFIFO");

    return 0;
}
