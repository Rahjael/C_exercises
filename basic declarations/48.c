#include <stdio.h>

int main() {

/*
Write a C program to read and print the elements 
of an array of length 7, before print replace 
every negative number, zero with 100.
*/


int numbers[7];

for (int i=0; i<7; i++){
    printf("Insert a number:\n");
    scanf("%d", &numbers[i]);
    if (numbers[i] < 0 || numbers[i] == 0){
        numbers[i] = 100;
        printf("Number was negative or zero. Replaced with 100.\n");
    }
}

for (int i=0; i<7; i++){
    printf("%d\n", numbers[i]);
}




return 0;

}