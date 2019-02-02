#include <stdio.h>

int main() {

/*
Write a C program to calculate the value of S where S = 1 + 1/2 + 1/3 + … + 1/50.
*/

float S=0;


for (int i=1; i < 51; i++){

    S += (float)1/i;
    printf("%f\n", S);
}

printf("S = %.2f", S);





return 0;

}