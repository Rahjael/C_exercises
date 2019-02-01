#include <stdio.h>

int main() {

int a, b, c, intsum;

float x, y, z, floatsum;


a = 2;
b = 3;

x = 2.5;
y = 3.5;

intsum = a+x;
floatsum = b+y;

printf("Intsum = %d\n\n", intsum);

printf("Floatsum = %f\n\n", floatsum);

/*
printf("Intsum = %f\n\n", intsum);

printf("Floatsum = %d\n\n", floatsum);
*/
return 0;

}