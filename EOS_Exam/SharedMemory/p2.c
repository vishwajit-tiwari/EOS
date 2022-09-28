/**
 * @file p2.c
 * @author your name (you@domain.com)
 * @brief A Shared Memory Progream to read data comming from Process P1 and find the count of 's'
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
unsigned char buffp2[MAX_SIZE];
char *ptr_mmap;
int count;


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

    // /**********Read data from open file************/
    // retRead = read(openfd, buffp2, sizeof(buffp2));
    // if(retRead<0) {
    //     perror("error in read sys call");
    //     exit(EXIT_FAILURE);
    // }
    // printf("read sys call : success\n");
    // printf("read : %ld-bytes\n", retRead);
    // /*****************************************************/

    //Move to predefined length
    ret_ftruncate = ftruncate(ret_shm_open, sizeof(char));
    if(ret_ftruncate<0) {
        perror("error in ftruncate");
        exit(EXIT_FAILURE);
    }
    else printf("ftruncate : success\n");

    //Map or Unmap files into memory
    ptr_mmap = (char *)mmap(NULL, sizeof(char), PROT_READ | PROT_WRITE, MAP_SHARED, ret_shm_open, 0);
    if(ptr_mmap == MAP_FAILED) {
        perror("error in mmap");
        exit(EXIT_FAILURE);
    }
    else printf("mmap : success\n");

    //Receive data from Process P1
    // int length = strlen(buffp2);
    // if(buffp2[length-1] == '\n') {
    //     buffp2[length-1] = '\0';
        strcpy(buffp2,ptr_mmap);
        printf("\n%s\n",buffp2);
    // }
    
    // printf("s occured : %d times\n", count);

    return 0;
}
