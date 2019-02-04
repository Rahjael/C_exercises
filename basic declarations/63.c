#include <stdio.h>

int main() {

/*
Write a C program that accepts a positive integer n less than 100 
from the user and prints out the sum 
1^4 + 2^4 + 4^4 + 7^4 + 11^4 + • • • + m^4 , 
where m is less than or equal to n. Print appropriate message.
*/

int num, sum=0, z=1;
printf("Insert a positive integer < 100:\n");
scanf("%d", &num);

for(int i=1; z<=num; i++){
    
    sum += (z*z*z*z);
    printf("%d\n", sum); //Debug
    z += i;
}

printf("Sum is %d", sum);


return 0;

}