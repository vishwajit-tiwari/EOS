/**
 * @file p1.c
 * @author Vishwajit Kumar Tiwari (tvishwajit@cdac.in)
 * @brief A Sender code for mkfifo
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
unsigned char Buffp1[MAX_SIZE];



int main(int argc, char const *argv[])
{
    int openfdFIFO, openfdFile;
    ssize_t retRead, retWrite;
    
    printf("Inside Process P1 : %s() function\n", __FUNCTION__);

    // Open cmd FIFO for communication b/w two process
    openfdFIFO = open("MKFIFO", O_WRONLY);
    if(openfdFIFO<0) {
        perror("error in open sys FIFO ");
        exit(EXIT_FAILURE);
    }

    printf("FIFO opened successfully\n");

    // open specified file 
    openfdFile = open("/usr/include/stdio.h", O_RDONLY);
    if(openfdFile<0) {
        perror("error in open FILE ");
        exit(EXIT_FAILURE);
    }

    printf("Specified file opened successfully\n");

    // Read data from specified file
    retRead = read(openfdFile, Buffp1, sizeof(Buffp1));
    if(retRead<0) {
        perror("error in read sys call ");
        exit(EXIT_FAILURE);
    }

    printf("Successfully read : %ld bytes\n", retRead);

    //Sned data to process p2
    retWrite = write(openfdFIFO, Buffp1, sizeof(Buffp1));
    if(retWrite<0) {
        perror("error in write sys call ");
        exit(EXIT_FAILURE);
    } 

    printf("successfully written : %ld bytes\n", retWrite);

    close(openfdFile);
    close(openfdFIFO);

    return 0;
}

