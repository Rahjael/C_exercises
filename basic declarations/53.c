#include <stdio.h>

int main() {


/*
Write a C program that accepts principle, rate of interest, 
time and compute the simple interest. 
*/

float amount, rate, time;

printf("Insert amount:\n");
scanf("%f", &amount);
printf("Insert rate (%%):\n");
scanf("%f", &rate);
printf("Insert time (years):\n");
scanf("%f", &time);



printf("Simple interest is: %.2f", (amount*rate*time)/100);







return 0;

}