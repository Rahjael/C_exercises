#include <stdio.h>

/*
Write a C program to check two given integers 
whether either of them is in the range 100..200 inclusive
*/

int main(){

    int a, b;

    printf("Insert 2 integers:\n");
    scanf("%d", &a);
    scanf("%d", &b);

    if( (a>100 && a<200) || (b>100 && b<200)){

        printf("\nAt least one number is >100 and <200 \n");
    }
    else
    {
        printf("\n Numbers out of range\n");
    }
    


    return 0;
}