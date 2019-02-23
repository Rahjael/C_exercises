#include <stdio.h>
#include <stdlib.h>

/*
Write a C program to check which number nearest to the value 100
 among two given integers. Return 0 if the two numbers are equal.
*/


int main(){

    int a = 34;
    int b = 67;

    if (a==b){
        return 0;
    }
    else if (abs(a-100) > abs(b-100)){
        printf("B is bigger\n");
    }
    else if (abs(b-100) > abs(a-100)){
        printf("A is bigger\n");
    }
    else
    {
        printf("Boh");
    }
    

    return 0;
}