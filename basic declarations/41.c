#include <stdio.h>

int main() {

/*
Write a C program to print 3 numbers in a line, 
starting from 1 and print n lines. 
Accept number of lines (n, integer) from the user. 
*/

int lines, start = 0;

printf("How many lines?\n");
scanf("%d", &lines);

for (; lines > 0; lines--){
    printf("%d %d %d\n", start+1, start+2, start+3);
    start += 3;
}

return 0;

}