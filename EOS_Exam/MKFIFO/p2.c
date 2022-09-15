/**
 * @file p2.c
 * @author Vishwajit Kumar Tiwari (tvishwajit@cdac.in)
 * @brief A Receiver code for mkfifo
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
#include <fcntl.h>
#include <unistd.h>

#define MAX_SIZE 81920

// Global Variables
unsigned char Buffp2[MAX_SIZE];
int count = 0;


int main(int argc, char const *argv[])
{
    int openfdFIFO;
    ssize_t retRead, retWrite;
    
    printf("Inside Process : P2 : %s() function\n", __FUNCTION__);

    // Open cmd FIFO for communication b/w two process
    openfdFIFO = open("MKFIFO", O_RDONLY);
    if(openfdFIFO<0) {
        perror("error in open sys FIFO ");
        exit(EXIT_FAILURE);
    }

    printf("FIFO opened successfully\n");

    // Receive data from FIFO
    retRead = read(openfdFIFO, Buffp2, sizeof(Buffp2));
    if(retRead<0) {
        perror("error in reading ");
        exit(EXIT_FAILURE);
    }

    printf("successfully read : %ld bytes\n", retRead);

    for(int i=0; /*i<sizeof(Buffp2)*/Buffp2[i] != '\0'; i++) {
        if(Buffp2[i] == 's') {
            count++;
        }
    }

    printf("In process : P2 : 's' occured = %d\n", count);

    close(openfdFIFO);

    return 0;
}

