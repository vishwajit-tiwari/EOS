/**
 * @file p1.c
 * @author your name (you@domain.com)
 * @brief A Shared Memory Progream to read data from "/usr/include/stdio.h" and send it to Process P2
 * @version 0.1
 * @date 2022-09-28
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include<stdio.h>
#include<stdlib.h>
//For shm_open()
#include <sys/mman.h>
#include <sys/stat.h>        /* For mode constants */
#include <fcntl.h>           /* For O_* constants */
//For ftruncate()
#include <unistd.h>
#include <sys/types.h>
//For mmap()
#include <sys/mman.h> 
//For string operations
#include<string.h>

//Global varaibles
#define MAX_SIZE 81920
unsigned char buffp1[MAX_SIZE];
char *ptr_mmap;


int main(int argc, char const *argv[])
{
    int ret_shm_open;
    int ret_ftruncate;
    int openfd;
    ssize_t retRead, retWrite;

    printf("Inside %s() Function\n", __FUNCTION__);

    //Open shared memeory space
    ret_shm_open = shm_open("/sharedmemory", O_RDWR | O_CREAT, S_IRUSR | S_IWUSR);
    if(ret_shm_open<0) {
        perror("error in shm_open");
        exit(EXIT_FAILURE);
    }
    else printf("shm_open : success\n");

    /**********Open intended file for reading************/
    openfd = open("/usr/include/stdio.h", O_RDONLY);
    if(openfd<0) {
        perror("error in open sys call");
        exit(EXIT_FAILURE);
    }
    printf("open sys call : success\n");

    //Read data from open file
    retRead = read(openfd, buffp1, sizeof(buffp1));
    if(retRead<0) {
        perror("error in read sys call");
        exit(EXIT_FAILURE);
    }
    printf("read sys call : success\n");
    printf("read : %ld-bytes\n", retRead);

    // retWrite = write(ret_shm_open,buffp1,sizeof(buffp1));
    // if(retWrite<0) {
    //     perror("error in read sys call");
    //     exit(EXIT_FAILURE);
    // }
    // printf("write sys call : success\n");
    // printf("written : %ld-bytes\n", retWrite);
    /*****************************************************/

    //Move to predefined length
    ret_ftruncate = ftruncate(ret_shm_open, MAX_SIZE);
    if(ret_ftruncate<0) {
        perror("error in ftruncate");
        exit(EXIT_FAILURE);
    }
    else printf("ftruncate : success\n");

    //Map or Unmap files into memory
    ptr_mmap = (char *)mmap(NULL, sizeof(buffp1), PROT_READ | PROT_WRITE, MAP_SHARED, ret_shm_open, 0);
    if(ptr_mmap == MAP_FAILED) {
        perror("error in mmap");
        exit(EXIT_FAILURE);
    }
    printf("mmap : success\n");
    printf("mapped area : %d\n",*ptr_mmap);


    //Send data to Process p2
    while(1) {
    int length = strlen(buffp1);
    if(buffp1[length-1] == '\n') {
        buffp1[length-1] = '\0';
        strcpy(ptr_mmap,buffp1);
        printf("\n%s\n",ptr_mmap);
    }
    }

    return 0;
}
