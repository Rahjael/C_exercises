#include <stdio.h>
#define CONVERSION 2.54


int main() {


/*
Write a C program that accepts a distance in 
centimeters and prints the corresponding value in inches.
*/


float inches, cm;
printf("Input the distance in cm:\n");
scanf("%f", &cm);
inches = cm / CONVERSION;
printf("Distance of %0.2f cms is = %0.2f inches\n", cm, inches);


return 0;

}