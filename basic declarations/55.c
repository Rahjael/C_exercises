#include <stdio.h>

int main() {

/*
Write a C program that swaps two numbers without using third variable.
*/

int a, b;

printf("Insert first number:\n");
scanf("%d", &a);
printf("Insert second number:\n");
scanf("%d", &b);

printf("You inserted the following values to swap: %d, %d\n", a,b);

a = a+b, b = a-b, a = a-b;

printf("Swapped values: %d, %d \n", a, b);



return 0;

}