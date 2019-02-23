#include <stdio.h>


/*

Write a C program to compute the sum of the two given integer 
values. If the two values are the same, 
then return triple their sum.

*/

int main(){


    int a, b;

    printf("Insert 2 integers:\n");
    scanf("%d", &a);
    scanf("%d", &b);

    if ( a == b){
        printf("\n%d", (a+b)*3);
    }
    else
    {
        printf("\n%d", a+b);
    }
    



    return 0;
}