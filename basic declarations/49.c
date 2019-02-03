#include <stdio.h>

int main() {

/*
Write a C program to read and print the elements of an array of length 7, 
before print, put the triple of the previous position 
starting from the second position of the array.
*/

int array[7];


printf("Insert a number:\n");
scanf("%d", &array[0]);

for (int i=1; i<7; i++){
    array[i] = array[i-1]*3;
    printf("%d\n", array[i]);
}



return 0;

}