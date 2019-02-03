#include <stdio.h>

int main() {

/*
Write a C program that reads an integer and find all its divisor. 
*/

int num;

printf("Insert a number:\n");
scanf("%d", &num);

for (int i=1; i <= num; i++){
    if (num%i == 0)
        printf("%d is a divisor of %d\n", i, num);
}

return 0;

}