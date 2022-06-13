#include<stdio.h>
#include<stdlib.h>
#include <sys/types.h>   // For Open system call
#include <sys/stat.h>
#include <fcntl.h>
#include<unistd.h>

#define MAX_SIZE_BUFF 32

int main(int argc, char const *argv[])
{
    int open_fd;
    ssize_t read_fd;
    unsigned char buff[MAX_SIZE_BUFF];

    open_fd = open("desdfifo", O_RDONLY);

    if(open_fd == -1) {
        perror("Error in open system call\n");
        exit(EXIT_FAILURE);
    }

    read_fd = read(open_fd,buff,sizeof(buff));

    if(read_fd == -1) {
        perror("Error in read system call\n");
        exit(EXIT_FAILURE);
    }
    else {
        printf("%ld bytes read successfully\n", read_fd);
        printf("Reciver: Data: >>>%s<<<\n", buff);
    }

    close(open_fd);
    
    return 0;
}
