/**
 * @file p2.c
 * @author Vishwajit Kumar Tiwari (tvishwajit@cdac.in)
 * @brief A Shared Memory Progream to read data comming from Process P1 and find the count of 's'
 * @version 0.1
 * @date 2022-09-28
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
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
//For Semaphore
#include<semaphore.h>

//Global varaibles
#define MAX_SIZE 81920
unsigned char buffp2[MAX_SIZE];
char *ptr_mmap;
int count;


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
    shmbuff *shmptr;              // Pointer to structure
    // struct shmBuff *shmp;

    printf("Inside %s() Function\n", __FUNCTION__);

    //Open shared memeory space
    ret_shm_open = shm_open("/sharedmemory", O_RDWR | O_CREAT | O_EXCL, S_IRUSR | S_IWUSR);
    if(ret_shm_open<0) {
        perror("error in shm_open");
        exit(EXIT_FAILURE);
    }
    else printf("shm_open : success\n");

    //Move to predefined length
    ret_ftruncate = ftruncate(ret_shm_open, sizeof(shmbuff));
    if(ret_ftruncate<0) {
        perror("error in ftruncate");
        exit(EXIT_FAILURE);
    }
    else printf("ftruncate : success\n");

    //Map or Unmap files into memory
    shmptr = mmap(NULL, sizeof(shmptr), PROT_READ | PROT_WRITE, MAP_SHARED, ret_shm_open, 0);
    if(shmptr == MAP_FAILED) {
        perror("error in mmap");
        exit(EXIT_FAILURE);
    }
    else printf("mmap : success\n");

    // memcpy();

    // Initialize Semaphores as process-shared, with value 0
    int retsem = sem_init(&shmptr->s1,1,0);
    if(retsem==-1) {
        perror("error in sem_init");
        exit(EXIT_FAILURE);
    }
    int retsem2 = sem_init(&shmptr->s2,1,0);
    if(retsem2==-1) {
        perror("error in sem_init");
        exit(EXIT_FAILURE);
    }

    //Receive data from Process P1
    // int length = strlen(ptr_mmap);
    // if(ptr_mmap[length-1] == '\n') {
    //     ptr_mmap[length-1] = '\0';

    // Wait for sem2 to be posted
    if(sem_wait(&shmptr->s2)==-1) {
        perror("error in sem_wait");
        exit(EXIT_FAILURE);
    }

    // strcpy(shmptr->buff,ptr_mmap);
    /*************Critical region***************/
    int i;
    for(i = 0; i < shmptr->cnt; i++) {
        buffp2[i] = shmptr->buff[i];
    }
    buffp2[i] = '\0';
    printf("\n%s\n",buffp2);
    /*******************************************/

    // Post sem1 to be used by P1
    if(sem_post(&shmptr->s1) == -1) {
        perror("error in sem_post");
        exit(EXIT_FAILURE);
    }
    printf("Data : received success\n");
    // }
    
    // printf("s occured : %d times\n", count);

    shm_unlink("/sharedmemory");

    return 0;
}
