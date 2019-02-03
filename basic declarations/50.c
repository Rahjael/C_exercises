#include <stdio.h>

int main() {


/*
Write a C program to read an array of length 5 and print the position 
and value of the array elements of value less than 5. 
*/

int array[5];

for (int i=0; i<5; i++){
printf("Insert a number:\n");
scanf("%d", &array[i]);
}


for (int i=0; i<5; i++){
    if (array[i] < 5)
    printf("array[%d] = %d\n", i, array[i]);
}


return 0;

}