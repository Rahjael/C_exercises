#include <stdio.h>

int main() {

int num1, num2, num3, max;

printf("Insert first number:");
scanf("%d", &num1);
printf("Insert second number:");
scanf("%d", &num2);
printf("Insert third number:");
scanf("%d", &num3);

max = (num1 > num2) ? num1 : num2;
max = (max > num3) ? max : num3;

printf("Maximum number is %d", max);




return 0;

}