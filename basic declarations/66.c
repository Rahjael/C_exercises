#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N max


int main() {

/*
Write a C program that generates 50 random numbers between -0.5 and 0.5 
and writes them in a file rand.dat. 
The first line of ran.dat contains the number of data and 
the next 50 lines contains the 50 random numbers.
*/


int i;

char str;

FILE * fptr;

fptr = fopen("rand.dat", "w");

if (fptr == NULL) 
    printf("Error in creating output.dat\n");


srand(time(NULL));

fprintf(fptr, "%d\n", N);

for (i = 1; i <= max; i++) {
    fprintf(fptr, "%0.4lf\n", (rand() % 2001 - 1000) / 2.e3);
}

fclose(fptr);

fptr = fopen ("rand.dat", "r");  

str = fgetc(fptr);

while (str != EOF){
    printf ("%c", str);
    str = fgetc(fptr);
}

fclose(fptr);





return 0;

}