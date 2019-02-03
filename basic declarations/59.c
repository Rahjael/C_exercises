#include <stdio.h>

int main() {


/*
Write a C program to display sum of series 1 + 1/2 + 1/3 + ………. + 1/n.
*/

int num;
float sum=0;

printf("Insert target number:\n");
scanf("%d", &num);

for (int i=1; i<=num; i++){
    sum += 1/(float)i;
    printf("%f\n", sum);
}

printf("Sum is %.2f", sum);



return 0;

}