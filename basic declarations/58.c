#include <stdio.h>
#define NUM 4
int main() {

/*
Write a C program that accepts 4 real numbers from the 
keyboard and print out the difference of the maximum 
and minimum values of these four numbers.
*/

float array[NUM];

for (int i=0; i<NUM;i++){
    printf("Insert a real number:\n");
    scanf("%f", &array[i]);    
}

printf("Your array contains the following values:");

for (int i=0; i<NUM-1;i++){
    printf("%f, ", array[i]);
    }

printf("%f.\n", array[NUM-1]);


//get maximum and minimum

float max = array[0], min = array[0];
for (int i=1; i<NUM; i++){
    if (array[i] > max)
        max = array[i];
    if (array[i] < min)
        min = array[i];
}

//calculate difference and print it

float diff = max - min;
printf("Difference between %f and %f is %f", max, min, diff);


return 0;


}