#include <stdio.h>

int main() {


/*
Write a C program to shift given data by two bits to the left.
*/

int a;

printf("Insert an integer:\n");
scanf("%d", &a);

a<<=3;

printf("Shifted value is: %d", a);





return 0;

}