#include <stdio.h>


/*
 Write a C program to get the absolute difference between n and 51. 
 If n is greater than 51 return triple the absolute difference.

 */

int main(){

    int n, dif;

    printf("Insert integer:\n");
    scanf("%d", &n);

    // Find absolute difference

    dif = n-51;

    if (dif < 0){
        dif *= -1;
    }

    if (n <= 51){
        printf("\nDifference is %d", dif);
    }
    else
    {
        printf("\nDifference is %d", dif*3);
    }
    

    return 0;
}