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

#include<semaphore.h>

//Global varaibles
#define MAX_SIZE 81920
unsigned char buffp1[MAX_SIZE];
char *ptr_mmap;
// sem_t s1, s2;

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

    char *stringPtr = buffp1;
    size_t len = strlen(stringPtr);
    /*****************************************************/

    //Open shared memeory space
    ret_shm_open = shm_open("/sharedmemory", O_RDWR | O_CREAT, S_IRUSR | S_IWUSR);
    if(ret_shm_open<0) {
        perror("error in shm_open");
        exit(EXIT_FAILURE);
    }
    else printf("shm_open : success\n");


    // //Move to predefined length
    // ret_ftruncate = ftruncate(ret_shm_open, MAX_SIZE);
    // if(ret_ftruncate<0) {
    //     perror("error in ftruncate");
    //     exit(EXIT_FAILURE);
    // }
    // else printf("ftruncate : success\n");

    //Map or Unmap files into memory
    shmptr = mmap(NULL, sizeof(shmptr), PROT_READ | PROT_WRITE, MAP_SHARED, ret_shm_open, 0);
    if(shmptr == MAP_FAILED) {
        perror("error in mmap");
        exit(EXIT_FAILURE);
    }
    printf("mmap : success\n");
    printf("mapped area : %d\n",*shmptr);

    // Copy data into shared memory object
    shmptr->cnt = len;
    memcpy(&shmptr->buff,stringPtr,len);

    // Initialize Semaphore
    // int retsem = sem_init(&shmptr->s1,1,0);
    // if(retsem==-1) {
    //     perror("error in sem_init");
    //     exit(EXIT_FAILURE);
    // }
    // int retsem2 = sem_init(&shmptr->s2,1,0);
    // if(retsem2==-1) {
    //     perror("error in sem_init2");
    //     exit(EXIT_FAILURE);
    // }

    //Send data to Process p2
    int length = strlen(buffp1);
    if(buffp1[length-1] == '\n') {
        buffp1[length-1] = '\0';

        // Wait for sem1 to be posted
        if(sem_wait(&s1)==-1) {
            perror("error in sem_wait");
            exit(EXIT_FAILURE);
        }

        strcpy(shmptr,buffp1);
        printf("\n%s\n",shmptr);

        // Post sem2 to be used by P2
        if(sem_post(&s2) == -1) {
            perror("error in sem_post");
            exit(EXIT_FAILURE);
        }
        printf("Data : sent success\n");
    }

    //Unlink shared memory object
    shm_unlink("/sharedmemory");

    return 0;
}
