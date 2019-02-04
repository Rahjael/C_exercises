#include <stdio.h>
#include <math.h>
int main() {


/*
Write a C program that accepts a real number x and prints 
out the corresponding value of sin(1/x) using 4-decimal places.
*/

float num;

printf("Insert a real number:\n");
scanf("%f", &num);

if (num == 0){
    printf("Value should not be zero.");
}
else{
    num = sin(1/num);
    printf("Sin 1/x is %.4f\n", num);
}



return 0;

}