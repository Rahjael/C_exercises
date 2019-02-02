#include <stdio.h>

/* Write a C program that read 5 numbers 
and sum of all odd values between them.*/

int main() {

int numbers[5], sum = 0;

for (int i=0; i<5; i++){

    printf("Insert a number:\n");
    scanf("%d", &numbers[i]);
    printf("Number %d inserted in position %d\n", numbers[i], i+1);

    if (numbers[i]%2 !=0)
        sum += numbers[i];
}

printf("You inserted the following numbers:\n");

for (int i=0; i<5; i++){
    printf("Position %d, number %d\n", i+1, numbers[i]);
}

printf("The sum of all odd numbers is %d", sum);

return 0;

}