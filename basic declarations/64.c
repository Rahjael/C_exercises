#include <stdio.h>

int main() {

/*
Write a C program that accepts integers from the user 
until a zero or a negative number, display the number 
of positive values, the minimum value, the maximum value 
and the average of all numbers.
*/

int num, positive=0, min, max, sum=0, first_time=1;
float avg;

// primo inserimento
printf("Insert an integer > 0:\n");
scanf("%d", &num);

// controllo che il primo inserimento sia corretto,
// altrimenti chiede ad oltranza
while (num <= 0){
    printf("Invalid number. Try again with a positive integer:\n");
    scanf("%d", &num);
}

// Se il primo inserimento è corretto, chiede numeri ad 
// oltranza. Un numero <= 0 termina il programma.

while (num > 0){

    // check if first number
    // set false after first
    if (first_time == 1)
        first_time=0;

    // track how many numbers
    positive++;

    // and keep track of sum
    sum += num;

    // track max and min
    if (first_time == 1){
        max = num;
        min = num;
    }
    else
        {
        if (num > max)
            max = num;
        if (num < min)
            min = num;
    }    

    // calculate avg
    avg = (float)sum/(float)positive;


    printf("\nPartial results:");
    printf("\nInserted: %d numbers, Max: %d, Min: %d, Avg: %.2f", positive, max, min, avg);

    printf("\n\nInsert another integer > 0, or <=0 to exit:\n");
    scanf("%d", &num);
   
}

printf("Quitting program.\n");
printf("\n\nResults:");

printf("\nPositive numbers: %d", positive);
printf("\nMaximum value: %d", max);
printf("\nMinimum value: %d", min);
printf("\nAverage value: %.2f", avg);

return 0;

}