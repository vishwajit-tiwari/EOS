#include<stdio.h>
#include<stdlib.h>

#include <sys/types.h>
#include <unistd.h>

int main(int argc, char const *argv[])
{
    pid_t id;

    printf("Before fork\n");
    printf("Process: ID: %d PPID: %d\n", getpid(),getppid());

    id = fork();

    printf("After fork\n");
    
    if(id == 0){
        printf("Child process: ID: %d PPID: %d\n", getpid(),getppid());
    }
    else if(id > 0) {
        printf("Parent process: ID %d PPID: %d\n", getpid(), getppid());
    }
    else {
        perror("Error in fork\n");
        exit(EXIT_FAILURE);
    }
    
    exit(EXIT_SUCCESS);
    //return 0;
}
