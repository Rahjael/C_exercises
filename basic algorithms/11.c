#include <stdio.h>

/*
Write a C program to check whether two given integers
are in the range 40..50 inclusive, or they are both in the range 50..60 inclusive
*/

int main(){

    int a, b;

    printf("Insert 2 integers:\n");
    scanf("%d", &a);
    scanf("%d", &b);

    if ( (a>=40 && a<=50) && (b>=40 && b<=50)){
        printf("Both in range 40-50\n");
    }
    else if ( (a>=50 && a<=60) && (b>=50 && b<=60)){
        printf("Both in range 50-60\n");
    }
    else
    {
        printf("Not in range\n");
    }
    



    return 0;
}