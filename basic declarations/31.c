#include <stdio.h>

int main() {


/*
Write a C program to check a given integer 
is positive even, negative even, 
positive odd or negative odd. Print even if the number is 0.
*/


int target;

// get input
printf("Insert an integer:");
scanf("%d", &target);


// checks

if (target == 0)
    printf("Number is 0.");
else if (target > 0 && (target%2) == 0)
    printf("Number is positive even");
else if (target > 0 && (target%2) != 0)
    printf("Number is positive odd");
else if (target < 0 && (target%2) == 0)
    printf("Number is negative even");
else if (target < 0 && (target%2) !=0)
    printf("Number is negative odd");

return 0;

}