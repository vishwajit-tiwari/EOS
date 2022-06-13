#include<stdio.h>
#include<stdlib.h>
#include <sys/types.h>   // For Open system call
#include <sys/stat.h>
#include <fcntl.h>
#include<unistd.h>


int main(int argc, char const *argv[])
{
    int open_fd;
    ssize_t write_fd;

    open_fd = open("desdfifo",O_WRONLY);

    if(open_fd == -1) {
        perror("Error in Open system call\n");\
        exit(EXIT_FAILURE);
    }

    write_fd = write(open_fd,"Hello from Sender\n",19);

    if(write_fd == -1) {
        perror("Error while writing\n");
        exit(EXIT_FAILURE);
    }
    else {
        printf("%ld bytes written successfully\n",write_fd);
    }

    close(open_fd);    
    
    return 0;
}
