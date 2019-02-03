#include <stdio.h>

int main() {


/*
Write a C program to reverse and print a given number.
*/


int num, x, new=0;
printf("Input a number: \n");
scanf("%d",&num);
printf("Original number = %d\n",num);
while(num>=1){
    x = num%10;
    new = new*10+x;
    num = num/10;
    printf("x = %d new = %d, num = %d\n", x, new, num);
}
printf("\nReverse = %d", new);


return 0;

}