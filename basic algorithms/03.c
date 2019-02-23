#include <stdio.h>


/*
Write a C program to check two given integers, 
and return true if one of them is 30 or if their sum is 30.
*/


int main(){

    int a, b;

    printf("Insert 2 integers:\n");
    scanf("%d", &a);
    scanf("%d", &b);


    if (a == 30 || b == 30 || (a+b) == 30){
        return 1;
    }
    else
    {
        return 0;
    }
    
}