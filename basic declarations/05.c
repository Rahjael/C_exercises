#include <stdio.h>

int main() {

/*
Write a C program to compute the perimeter and area of a 
rectangle with a height of 7 inches. and width of 5 inches.
*/


int width = 5;
int height = 7;

int perimeter = (width*2)+(height*2);
int area = width*height;

printf("Perimeter of the rectangle = %d inches\n", perimeter);
printf("Area of the rectangle = %d square inches\n", area);


return 0;

}