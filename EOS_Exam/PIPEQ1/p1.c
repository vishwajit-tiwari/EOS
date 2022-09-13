/**
 * @file p1.c
 * @author Vishwajit Kumar Tiwari (tvishwajit@cdac.in)
 * @brief P1 opens a file "/usr/include/stdio.h" read data from the file and send it to P2. 
 * @version 0.1
 * @date 2022-09-09
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include<stdio.h>
#include<stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include<unistd.h>

// Max Buffer Size
#define MAXBUFF 81920

// Global Buffer
unsigned char BuffP1[MAXBUFF];
unsigned char BuffP2[MAXBUFF];
int count = 0;

int main(int argc, char const *argv[])
{
    int fd, pipefd[2], retPIPE;
    pid_t retFork;
    ssize_t retRead, retWrite;


    printf("Inside %s Function\n", __FUNCTION__);

    /***********To create link between two related processes*********/
    retPIPE = pipe(pipefd);

    if(retPIPE<0) {
        perror("error in PIPE: ");
        exit(EXIT_FAILURE);
    }

    /******************Create Two realted processes*******************/
    retFork = fork();

    if(retFork == -1) {
        perror("error in fork : ");
        exit(EXIT_FAILURE);
    }
    else if(retFork == 0) {
        /********************** P1 : Child Process *********************/
        printf("P1 : Child Process  : PID : %d PPID : %d\n", getpid(), getppid());
        

        /********************* Open the specifide file *****************/
        fd = open("/usr/include/stdio.h", O_RDONLY);
        if(fd<0) {
            perror("error in Open: ");
            exit(EXIT_FAILURE);
        }
        printf("File Open successfully\n");

        /*****************Read Data from file descriptor****************/
        retRead = read(fd, BuffP1, sizeof(BuffP1));
        if(retRead<0) {
            perror("error in read sys call: ");
            exit(EXIT_FAILURE);
        }
        printf("Number of bytes read in P1 : Child Process = %ld\n", retRead);

        /*****************Writing/Sending data to P2*********************/
        close(pipefd[0]);
        retWrite = write(pipefd[1], BuffP1, sizeof(BuffP1));
        if(retWrite<0) {
            perror("error in write : ");
            exit(EXIT_FAILURE);
        }
        printf("Number of bytes written from P1 : Child Process = %ld\n", retWrite);

    }
    else {
        /****************************** P2 : Parent Process *****************************/
        printf("P2 : Parent Process : PID : %d PPID : %d\n", getpid(), getppid());

        // Read data comming from P1
        close(pipefd[1]);

        retRead = read(pipefd[0], BuffP2, sizeof(BuffP2));
        if(retRead<0) {
            perror("error in read sys call in P2 : ");
            exit(EXIT_FAILURE);
        }

        printf("Number of bytes read in P2 : Parent Process = %ld\n", retRead);

        // Check occurence of letter/character 's' in the incoming data from P1
        for(int i = 0; i<sizeof(BuffP2); i++)
        {
            if(BuffP2[i] == 's') {
                count++;
            }
        }

        printf("Letter/Character 's' occurence = %d\n", count);

    }   
    
    return 0;
}
