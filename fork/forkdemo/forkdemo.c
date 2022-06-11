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
    
    return 0;
}
