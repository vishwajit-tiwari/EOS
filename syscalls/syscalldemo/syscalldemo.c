#include<stdio.h>
#include<stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>


int main(int argc, char const *argv[])
{
    int open_fd;
    ssize_t write_ret;

    open_fd = open("desdlog.txt", O_CREAT | O_RDWR);

    if(open_fd == -1){
        perror("error open system call...\n");
        exit(EXIT_FAILURE);
    }
    else{
        printf("Successfully open desdlog.txt file...\n");
    }    

    write_ret = write(open_fd,"hello from write system call\n",30);

    if(write_ret == -1){
        perror("Error in write system call...\n");
        exit(EXIT_FAILURE);
    }
    else {
        printf("Successfully written = %ld bytes\n", write_ret);
    }

//    return 0;
    exit(EXIT_SUCCESS);
}
