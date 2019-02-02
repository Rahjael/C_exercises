#include <stdio.h>

int main() {

/*
Write a C program to print a number, it’s square and cube in a line, 
starting from 1 and print n lines. 
Accept number of lines (n, integer) from the user.
*/

int lines, start = 1;

printf("How many lines?\n");
scanf("%d", &lines);


for (; lines > 0; lines--){
    printf("%d %d %d\n", start, start*start, start*start*start);
    start++;
}



return 0;

}


