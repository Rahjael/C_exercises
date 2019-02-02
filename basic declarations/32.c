#include <stdio.h>

int main() {

/*
Write a C program to print all numbers between 1 to 500 
which divided by a specified number and the remainder will be 3
*/


int target, i;
printf("Input an integer: ");
scanf("%d", &target);

for(i = 1; i <= 500; i++)
{
    if((i%target) == 3) {
        printf("%d\n", i);
    }
}


return 0;

}