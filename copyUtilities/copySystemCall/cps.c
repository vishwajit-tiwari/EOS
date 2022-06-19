#include <stdio.h>
#include<stdlib.h>

#include <sys/types.h>      // for Open system call
#include <sys/stat.h>
#include <fcntl.h>

#include<unistd.h>          // for Read system call

#define MAX_SIZE 8192
char buff[MAX_SIZE];

int main(int argc, char const *argv[])
{
    int open_fd1, open_fd2;
    ssize_t read_ret, write_ret, write_out;
    int srcFileSize;                        // for Source file size
    int close_fd1, close_fd2;

    // Open Source file for reading
    open_fd1 = open(argv[1], O_RDONLY);

    if(open_fd1 == -1) {
        perror("Error openinig Source file\n");
        exit(EXIT_FAILURE);
    }

    // Open Destination file for Writing 
    open_fd2 = open(argv[2], 0666);     

    if(open_fd2 == -1) {
        perror("Error opening Destination file\n");
        exit(EXIT_FAILURE);
    }

    // To check Souce file Size is not greater than Our Buffer Size
    srcFileSize = atoi(argv[1]);
    if(srcFileSize > MAX_SIZE) {
        perror("Source file size is greater than Buffer\n");
        exit(EXIT_FAILURE);
    }

    // Now read content of Source file & write into Destination file
    while((read_ret = read(open_fd1, (void *)buff, sizeof(buff))) != 0) 
    {
        if(read_ret < 0) {
            perror("Error reading source file\n");
            exit(EXIT_FAILURE);
        }

        write_out = 0; 

        // Write to the Destination file till write bytes equals to read bytes
        do 
        {
            write_ret = write(open_fd2, &buff[write_out], read_ret-write_out);
            if(write_ret < 0) {
                perror("Error writing file\n");
                exit(EXIT_FAILURE);
            }

            write_out += write_ret;
        }
        while(write_out < read_ret);

    }

    // Print this message when copy successfull
    printf("\nContents copied to %s\n", argv[2]);

    // Now close the open file descriptors for future reuse 
    close_fd1 = close(open_fd1);
    if(close_fd1 == -1) {
        perror("error closing source file\n");
        exit(EXIT_FAILURE);
    }

    close_fd2 = close(open_fd2);
    if(close_fd2 == -1) {
        perror("error closing destination file\n");
        exit(EXIT_FAILURE);
    }

    return 0;
}
