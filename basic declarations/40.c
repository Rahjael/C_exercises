#include <stdio.h>

int main() {


/*
Write a C program to find all numbers which 
dividing it by 7 and the remainder is 
equal to 2 or 3 between two given integer numbers
*/

int num1, num2, sum=0;

printf("Insert a number:\n");
scanf("%d", &num1);
printf("Insert a number:\n");
scanf("%d", &num2);


for (int i=num1; i <= num2; i++){
    if (i%7 == 2 || i%7 == 3)
        printf("%d\n", i);

}







return 0;

}