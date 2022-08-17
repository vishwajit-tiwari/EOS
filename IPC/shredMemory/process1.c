/**
 * @file process1.c
 * @author Vishwajit Kumar Tiwari (you@domain.com)
 * @brief IPC Machanisum to communicate between two Process
 * @version 0.1
 * @date 2022-08-17
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include<stdio.h>
#include <sys/mman.h>
#include <sys/stat.h>        /* For mode constants */
#include <fcntl.h>           /* For O_* constants */
#include <unistd.h>
#include <sys/types.h>

// Global Variables
int *count;
int num;


int main(int argc, char const *argv[])
{
    int shmd;

    printf("Inside %s: Function\n", __FUNCTION__);

    // Open shared memory
    shmd = shm_open("/cdacshm", O_RDWR | O_CREAT, S_IRUSR | S_IWUSR);

    // Move to predefined length
    ftruncate(shmd,sizeof(int));

    count = (int*) mmap(NULL, sizeof(int), PROT_READ | PROT_WRITE, MAP_SHARED, shmd, 0);

    while(1)
    {
        printf("Enter num = ");
        scanf("%d", &num);
        *count = num;
    }
    
    return 0;
}
