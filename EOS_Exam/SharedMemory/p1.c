/**
 * @file p1.c
 * @author Vishwajit Kumar Tiwari (tvishwajit@cdac.in)
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
//for semaphore
#include<semaphore.h>
// for shared memory
#include<sys/shm.h>

//Global varaibles
#define MAX_SIZE 81920
unsigned char buffp1[MAX_SIZE];
int ret_shm_open;
int ret_ftruncate;
int openfd;
ssize_t retRead, retWrite;

typedef struct shmBuff{
    sem_t s1;               // POSIX unnamed semaphore 
    sem_t s2;               // POSIX unnamed semaphore 
    size_t cnt;             // Number of bytes used in buffer
    char buff[MAX_SIZE];    // Data being tranferred

} shmbuff;


int main(int argc, char const *argv[])
{
    shmbuff *shmptr;        // Pointer to structure

    printf("Inside %s() Function\n", __FUNCTION__);

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

    char *string = buffp1;
    size_t len = strlen(string);
    printf("len = %ld-bytes\n", len);
    /*****************************************************/

    //Open shared memeory space
    ret_shm_open = shm_open("/sharedmemory", O_RDWR, 0);
    if(ret_shm_open<0) {
        perror("error in shm_open");
        exit(EXIT_FAILURE);
    }
    else printf("shm_open : success\n");

    //Map or Unmap files into memory
    shmptr = mmap(NULL, MAX_SIZE, PROT_READ | PROT_WRITE, MAP_SHARED, ret_shm_open, 0);
    if(shmptr == MAP_FAILED) {
        perror("error in mmap");
        exit(EXIT_FAILURE);
    }
    printf("mmap : success\n");

    // Print the number of bytes used in buffer
    shmptr->cnt = len;
    printf("cnt = %ld-bytes\n",shmptr->cnt);

    // Copy data into the shared memory object
    memcpy(&shmptr->buff,buffp1,len);
    printf("memcpy : success\n");
    // printf("\nBuffer data :%s\n", shmptr->buff);

    // Post sem1 to be used by P2
    if(sem_post(&shmptr->s1) == -1) {
        perror("error in sem_post");
        exit(EXIT_FAILURE);
    }
    printf("sem_post : s1 : success\n");

    //Print content of shared memory buffer
    // printf("\n%s\n",shmptr->buff);

    // Wait for sem2 to be posted
    if(sem_wait(&shmptr->s2)==-1) {
        perror("error in sem_wait");
        exit(EXIT_FAILURE);
    }
    printf("sem_wait : s2 : success\n");    
    printf("Data : sent success\n");

    //Unlink shared memory object
    shm_unlink("/sharedmemory");

    return 0;
}
