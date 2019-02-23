#include <stdio.h>


/*
Write a C program to check if a given positive number is a multiple of 3 or a multiple of 7
*/


int main(){

    int n;

    printf("Insert positive integer:\n");
    scanf("%d", &n);

    if(n%3 == 0){
        printf("%d is multiple of 3\n", n);
    }

    if(n%7 == 0){
        printf("%d is multiple of 7\n", n);
    }



    return 0;
}