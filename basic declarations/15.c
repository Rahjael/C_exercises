#include <stdio.h>
#include <math.h>
int main() {


int x1, x2, y1, y2, dx, dy;
float distance;

x1 = 25;
y1 = 15;
x2 = 35;
y2 = 10;


distance = sqrt((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1));

printf("The distance is %f", distance);

return 0;

}