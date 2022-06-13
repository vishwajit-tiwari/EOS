#include<stdio.h>
#include<stdlib.h>
#define _GNU_SOURCE  /* See feature_test_macros(7) */
#include <fcntl.h>   /* Obtain O_* constant definitions */
#include <unistd.h>  /* For PIPE */
#include <sys/types.h> /* for Fork */
#include <unistd.h>

#define MAX_BUFF_SIZE 32

int main(int argc, char const *argv[])
{
    int pipefd[2];   // For reading & writing
    // pipefd[0] is for reading
    // pipefd[1] is for writing
    int pipe_ret;
    pid_t fork_ret;
    ssize_t write_ret, read_ret;
    unsigned char buff[MAX_BUFF_SIZE];

    pipe_ret = pipe(pipefd);   // To create link between two processes

    if(pipe_ret  == -1) {
        perror("Error while creating PIPE\n");
        exit(EXIT_FAILURE);
    }

    fork_ret = fork();   // To create two related processes

    if(fork_ret == -1) {
        perror("Error while fork\n");
        exit(EXIT_FAILURE);
    }
    else if(fork_ret == 0) {
        // Child Process
        close(pipefd[1]);
        printf("Child Process: ID: %d PPID: %d\n", getpid(), getppid());
        read_ret = read(pipefd[0],buff,sizeof(buff));
        if(read_ret == -1) {
            perror("Error while reading\n");
            exit(EXIT_FAILURE);
        }
        else {
            printf("Child: Received Data: >>>>> %s <<<<<\n",buff);
            printf("%ld bytes read successfully\n", read_ret);
        }
    }
    else {
        // Parent Process
        close(pipefd[0]);
        printf("Parent Process: ID: %d PPID: %d\n", getpid(), getppid());
        write_ret = write(pipefd[1],"Hello from Parent Process",26);
        if(write_ret == -1) {
            perror("Error while writing\n");
            exit(EXIT_FAILURE);
        }
        else {
            printf("Parent: Wrote Data\n");
            printf("%ld bytes written successfully\n", write_ret);
        }
    }
    
    return 0;
}
