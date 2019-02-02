#include <stdio.h>

int main() {

/*
Write a C program that reads two integers p and q, 
print p number of lines in a sequence of 1 to b in a line.
*/

int lines, chars, counter=1;

printf("Insert number of lines:\n");
scanf("%d", &lines);
printf("Insert number of characters:\n");
scanf("%d", &chars);

for (; lines > 0; lines--){
    for (int i=chars; i > 0; i--){
        printf("%d ", counter);
        counter++;
    }
printf("\n");

}


return 0;
}