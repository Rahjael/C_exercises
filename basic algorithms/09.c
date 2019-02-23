#include <stdio.h>


/*
Write a C program to check whether two given integer 
values are in the range 20..50 inclusive. 
Return true if 1 or other is in the said range otherwise false.
*/


int main(){

    int a = 34;
    int b = 23;

    if ( (a>=20 && a<=50) || (b>=20 && b<=50)){

        printf("\nAt least one in range\n");
    }
    else
    {
        printf("None in range");
    }
    


    return 0;
}