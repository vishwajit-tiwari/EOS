#include<stdio.h>
#include "arith.h"

int main(int argc, char const *argv[])
{
    int num1,num2;
    
    printf("Enter two numbers: ");
    scanf("%d %d", &num1,&num2);

    printf("sum = %d\n", add(num1,num2));
    printf("diff = %d\n", sub(num1,num2));
    printf("product = %d\n", mul(num1,num2));
    printf("div = %d\n", div(num1,num2));
    
    return 0;
}
