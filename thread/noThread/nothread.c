/**
 * @file thread_attr.c
 * @author Vishwajit Tiwari (tvishwajit@cdac.in)
 * @brief Normal Function call Program
 * @version 0.1
 * @date 2022-07-10
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include<stdio.h>
#include<stdlib.h>

// Display Function
void * displayFun(void *data) 
{
    for(int i = 0; i < 5; ++i) {
        printf("In display function %d\n", i+1);
    }
}

int main(int argc, char const *argv[])
{  
    printf("Before Function call\n");
    displayFun(NULL);
    printf("After Function call\n");

    return 0;
}