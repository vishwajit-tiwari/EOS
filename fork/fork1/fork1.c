#include<stdio.h>
#include<stdlib.h>

#include <sys/types.h>
#include <unistd.h>

int main(int argc, char const *argv[])
{
    pid_t id;

    printf("Before fork\n");

    id = fork();

    printf("After fork\n");

    if(id == -1){
        perror("Error in fork\n");
        exit(EXIT_FAILURE);
    }
    else if(id == 0){
        printf("Child process\n");
        printf("child pid = %d\n", getpid());
        printf("Parent id ppid = %d\n", getppid());
    }
    else{
        printf("Parent process\n");
        printf("Parent id PID = %d\n", getpid());

    }
    
    return 0;
}
