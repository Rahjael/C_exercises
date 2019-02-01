#include <stdio.h>

int main() {

int integer = sizeof(int);
int floating = sizeof(float);
int doubled = sizeof(double);
int longed = sizeof(long int);

printf("integer %d\n", integer);
printf("floating %d\n", floating);
printf("doubled %d\n", doubled);
printf("longed %d\n", longed);

printf("\n\n\n\n");

int counter = 0;

for (int i=0; i<9; i++){
    counter++;
    printf("%d and %d\n", i, counter);

}






return 0;

}