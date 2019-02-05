#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int main() {


/*
Simple random int generator with range
*/

int lowest, highest, how_many;

printf("Insert lower limit:\n");
scanf("%d", &lowest);
printf("Insert highest limit:\n");
scanf("%d", &highest);
printf("How many numbers do you want to generate?");
scanf("%d", &how_many);

srand(time(0));

for (int i=0; i<how_many; i++){

    int num = (rand() % (highest - lowest + 1)) + lowest;

    printf("%d ", num);
}


















return 0;

}