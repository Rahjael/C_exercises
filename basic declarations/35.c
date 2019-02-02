#include <stdio.h>

/*
Write a C program to check if two numbers 
in a pair is in ascending order or descending order.
*/

int main() {

int num1, num2;

printf("Insert first number:\n");
scanf("%d", &num1);
printf("Insert second number:\n");
scanf("%d", &num2);

if (num1 > num2)
    printf("The numbers are in descending order");
else
{
    printf("The numbers are in ascending order");
}




return 0;

}