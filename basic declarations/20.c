#include <stdio.h>
#include <math.h>


int main() {

float a, b, c, delta;

float bask1, bask2;

printf("Insert number a:\n");
scanf("%f", &a);

printf("Insert number b:\n");
scanf("%f", &b);

printf("Insert number c:\n");
scanf("%f", &c);

delta = (b*b)-(4*a*c);

printf("\n\nDelta is: %d\n\n", delta);


if (delta > 0 && a !=0){

    bask1 = ((-b)+sqrt(delta))/(2*a);
    bask2 = ((-b)-sqrt(delta))/(2*a);

    printf("Root1 = %f\n", bask1);
    printf("Root2 = %f\n", bask2);
}
else
{
    printf("Error, there are no roots.");
}






return 0;

}