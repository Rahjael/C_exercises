#include <stdio.h>

#define NUM 5

/*
Write a C program that read 5 numbers and 
counts the number of positive numbers and print 
the average of all positive values. 
*/

int main() {

int array[NUM-1], sum = 0, counter = 0;


// user input NUM numbers

for (int i=0; i<NUM; i++){
    printf("Insert a positive or negative number:\n");
    scanf("%d", &array[i]);
}


for (int i=0; i<NUM; i++){
    printf("array %d is %d\n", i, array[i]);
}


// counter numeri positivi

for (int i=0; i<NUM; i++){
    counter = (array[i] > 0 ? counter + 1 : counter);
    sum = (array[i] > 0 ? sum + array[i] : sum);
    printf("sum = %d, counter = %d\n", sum, counter);

}







return 0;

}