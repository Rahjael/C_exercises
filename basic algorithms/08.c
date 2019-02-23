#include <stdio.h>


/*
Write a C program to check whether three given integer values
are in the range 20..50 inclusive. 
Return true if 1 or more of them are in the said range otherwise return false.
*/


int main(){

    int a = 4;
    int b = 56;
    int c = 35;

    if ( (a>=20 && a<=50) || (b>=20 && b<=50) || (c>=20 && c<=50)){
        printf("At least one of them is in range\n");
    }
    else
    {
        printf("None in range\n");
    }
    



    return 0;
}