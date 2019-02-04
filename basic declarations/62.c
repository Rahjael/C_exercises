#include <stdio.h>

int main() {


/*
Write a C program that accepts a positive integer 
less than 500 and prints out the sum 
of the digits of this number.
*/

int num, tmp, sum=0;

do{
printf("Insert an integer < 500:");
scanf("%d", &num);
if (num > 500)
    printf("Your number exceeds 500. Insert a number < 500");
}while (num > 500);

tmp = num;

while(tmp > 0){
    sum += tmp%10;
    tmp /= 10;
    printf("Sum %d tmp %d\n", sum, tmp);
}

printf("Number is %d. The sum of its digits is %d", num, sum);


return 0;

}