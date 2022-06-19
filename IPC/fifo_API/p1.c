
#include<stdio.h>
#include<stdlib.h>
#include <sys/types.h>              // for mkfifo & Open system call
#include <sys/stat.h>
#include <fcntl.h>                  // for Open system call 
#include<unistd.h>                  // for Write system call


int main(int argc, char const *argv[])
{
    int mkfifo_ret, open_fd, close_ret;
    ssize_t write_ret;

    // To create Named FIFO
    mkfifo_ret = mkfifo("desd_mkfifo",S_IRUSR | S_IWUSR);
    if(mkfifo_ret == -1) {
        perror("Error creating named fifo\n");
        exit(EXIT_FAILURE);
    }

    // Open newely created FIFO
    open_fd = open("desd_mkfifo", O_WRONLY);
    if(open_fd == -1) {
        perror("Error opening named fifo\n");
        exit(EXIT_FAILURE);
    }

    // Write to the open file desdcriptor
    write_ret = write(open_fd, "Hello from Process P1\n", 30);
    if(write_ret == -1) {
        perror("Error writing to file desdcriptor\n");
        exit(EXIT_FAILURE);
    }

    close_ret = close(open_fd);
    if(close_ret == -1) {
        perror("Error closing file descriptor\n");
        exit(EXIT_FAILURE);
    }

    unlink("desd_mkfifo");           // To remove named fifo

    return 0;
}
