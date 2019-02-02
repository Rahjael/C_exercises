#include <stdio.h>

int main() {

/*
Write a C program to find and print 
the square of each one of the even 
values from 1 to a specified value.
*/

int target;

printf("Insert a target number:\n");
scanf("%d", &target);

for (int i=0; i <= target; i++){
    if (i%2 == 0){
        printf("%d^2 = %d\n", i, i*i);

    }

}





return 0;

}