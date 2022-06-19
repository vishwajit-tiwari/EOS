
#include<stdio.h>
#include<stdlib.h>
#include <sys/types.h>              // for mkfifo & Open system call
#include <sys/stat.h>
#include <fcntl.h>                  // for Open system call 
#include<unistd.h>                  // for Write system call

#define MAX_SIZE 132
unsigned char buff[MAX_SIZE];

int main(int argc, char const *argv[])
{
    int mkfifo_ret, open_fd, close_ret;
    ssize_t read_ret;

    // Create named fifo using API for IPC
    // mkfifo_ret = mkfifo("desd_mkfifo", S_IRUSR | S_IWUSR);
    // if(mkfifo_ret == -1) {
    //     perror("Error creating named fifo\n");
    //     exit(EXIT_FAILURE);
    // }

    // Open named FIFO 
    open_fd = open("desd_mkfifo", O_RDONLY);
    if(open_fd == -1) {
        perror("Error opening named fifo\n");
        exit(EXIT_FAILURE);
    }

    // Read from file descriptor
    read_ret = read(open_fd, buff, sizeof(buff));
    if(read_ret == -1) {
        perror("Error reading from file descriptor\n");
        exit(EXIT_FAILURE);
    }
    else {
        printf("Successfully read %ld-bytes\n", read_ret);
        printf("P2: got data: >>>%s<<<\n", buff);
    }

    close_ret = close(open_fd);
    if(close_ret == -1) {
        perror("Error closing file descriptor\n");
        exit(EXIT_FAILURE);
    }

    unlink("desd_mkfifo");              // To remove named  FIFO

    return 0;
}
