#include <stdio.h>


/* Write a C program that accepts 4 integers p, q, r, s 
from the user where r and s are positive and p is even.
If q is greater than r and s is greater than p and if the sum
of r and s is greater than the sum of p and q print "Correct values", 
otherwise print "Wrong values"*/

int main() {


int p, q, r, s;


printf("Insert number r (must be a positive integer):\n");
scanf("%d", &r);
printf("Insert number s (must be a positive integer):\n");
scanf("%d", &s);
printf("Insert number p (must be even):\n");
scanf("%d", &p);
printf("Insert number q:\n");
scanf("%d", &q);

if ((q > r) && (s > p) && ((r+s) > (p+q)) && (r>0) && (s>0) && (p%2 == 0))
    {
    printf("\nCorrect values\n");
    }
else
    {
    printf("Wrong values");
    }


return 0;

}