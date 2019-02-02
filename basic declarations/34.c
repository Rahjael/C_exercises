#include <stdio.h>

int main() {

/*
Write a C program to print the numbers from the 
lowest to the highest (inclusive) and the 
sum of consecutive integers from a given pair of numbers.
*/

int num1, num2, sum=0;


// get integers

printf("Enter two integers:\n");
printf("Enter first number:");
scanf("%d", &num1);
printf("Enter second number:");
scanf("%d", &num2);

// order numbers if necessary

if (num1 > num2){
    num2 = num1+num2;
    num1 = num2-num1;
    num2 = num2-num1;
}

for (int i=num1; i<=num2; i++){
    sum += i;
}

printf("Sum is %d", sum);



return 0;

}