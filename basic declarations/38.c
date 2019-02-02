#include <stdio.h>

int main() {

/*
Write a program that reads two numbers and divide the first number by second number.
If the division not possible print "Division not possible"
*/

float num1, num2;

printf("Insert a number:\n");
scanf("%f", &num1);
printf("insert a number:\n");
scanf("%f", &num2);


if (num2 != 0)
    printf("%f / %f = %f", num1, num2, num1/num2);
else
{
    printf("division not possibile");
}





return 0;

}