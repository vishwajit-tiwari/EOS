#include<stdio.h>

#include "arith.h"

int main(int argc, char const *argv[])
{
    int num1,num2, choice;

    printf("Enter two numbers: ");
    scanf("%d %d",&num1,&num2);

    printf("Choose operation:\n");
    printf("1. for add\n2. for sub\n3. for mul\n4. for div\n");
    printf("Enter your choice: ");
    scanf("%d",&choice);

    switch (choice)
    {
    case 1: printf("Add = %d\n",add(num1,num2));
            break;
    case 2: printf("Sub = %d\n",sub(num1,num2));
            break;
    case 3: printf("Mul = %d\n",mul(num1,num2));
            break;
    case 4: printf("Div = %d\n",div(num1,num2));
            break;

    default: printf("Wrong Choice\n");
            break;
    }

    return 0;
}
