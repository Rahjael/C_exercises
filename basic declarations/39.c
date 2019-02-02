#include <stdio.h>

int main() {

/*
Write a C program to calculate the sum of all number 
not divisible by 17 between two given integer numbers.
*/

int num1, num2, sum=0;

printf("Insert a number:\n");
scanf("%d", &num1);
printf("Insert a number:\n");
scanf("%d", &num2);


for (int i = num1; i <= num2; i++){
    if (i%17 != 0)
        sum += i;
}


printf("The sum is %d", sum);


return 0;

}