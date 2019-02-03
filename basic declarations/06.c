#include <stdio.h>

int main() {

/*
Write a C program to compute the perimeter and area of a circle with a radius of 6 inches
*/


int radius = 6;

float perimeter = radius*2*3.14;
float area = radius*radius*3.14;

printf("Perimeter of the circle = %f inches\n", perimeter);
printf("Area of the circle = %f inches \n", area);

return 0;

}