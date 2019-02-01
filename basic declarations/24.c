#include <stdio.h>

int main() {

/*
Write a C program that reads two integers and checks 
if they are multiplied or not.
*/

int num1, num2;

printf("Insert an integer:\n");
scanf("%d", &num1);
printf("Insert another integer:\n");
scanf("%d", &num2);

if (num2 % num1 == 0)
    printf("The second number is a multiple of the first one");
else
{
    printf("The second number is not a multiple of the first one");
}
    





return 0;

}