#include<stdio.h>
#include<stdlib.h>
#include "header.h"

int a;
int b = 10;

int main(int argc, char const *argv[])
{
    int result = 0;
    int *p = NULL;

    printf("This is section demo prog\n");

    p = (int *)malloc(sizeof(int));
    result = add(a,b);

    printf("Size of int = %d\n", *p);
    printf("sum of %d & %d is = %d\n", a, b, result);

    return 0;
}


