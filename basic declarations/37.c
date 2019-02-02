#include <stdio.h>

int main() {


/*
Write a C program to read the coordinates(x, y) 
(in Cartesian system) and find the quadrant to which it belongs 
(Quadrant -I, Quadrant -II, Quadrant -III, Quadrant -IV).
Note: A Cartesian coordinate system is a coordinate system that specifies 
each point uniquely in a plane by a pair of numerical coordinates.
These are often numbered from 1st to 4th and denoted by Roman numerals: 
I (where the signs of the (x,y) coordinates are I(+,+), II (−,+), III (−,−), and IV (+,−).
*/

int x, y;

printf("Insert a number for X coordinate:\n");
scanf("%d", &x);
printf("Insert a number for Y coordinate:\n");
scanf("%d", &y);


if (x == 0 && y == 0){
    printf("Origine degli assi");
}
else if (x > 0 && y > 0){
    printf("I quadrant");
}
else if (x < 0 && y > 0){
    printf("II quadrant");
}
else if (x < 0 && y < 0){
    printf("III quadrant");
}
else if (x > 0 && y < 0){
    printf("IV quadrant");
}












return 0;





}