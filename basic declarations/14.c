#include <stdio.h>

int main() {

int distance;
float fuel, avg;

printf("Insert distance traveled (km):");
scanf("%d", &distance);
printf("Insert fuel spent (l):");
scanf("%f", &fuel);

avg = distance/fuel;

printf("Average consuption is %.2f km/lt", avg);






return 0;

}