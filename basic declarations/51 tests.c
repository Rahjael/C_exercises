#include <stdio.h>
#define NUM 10


int main() {

/*
Write a C program to read an array of length 6, 
change the first element by the last, the second element 
by the fifth and the third element by the fourth. 
Print the elements of the modified array.
*/


int array[NUM] = {0}, i=0;


printf("%d %d %d %d %d\n", array[0], array[1], array[2], array[3], array[4]); //debug


for (i=0; i<NUM; i++){
    printf("Insert an integer:\n");
    scanf("%d", &array[i]);
    printf("array[%d] is %d\n", i, array[i]); //debug
    printf("i = %d\n", i);
}

i = 0;

printf("i = %d\n", i);
    printf("%d %d %d %d %d\n", array[0], array[1], array[2], array[3], array[4]); //debug
printf("i = %d\n", i);
printf("inversione:\n"); //debug


for (i=0; i<NUM/2; i++){
    printf("\n\n\ni = %d\n", i); //debug
    printf("%d %d %d %d %d\n", array[0], array[1], array[2], array[3], array[4]); //debug
    array[i] = array[i]+array[NUM-1-i];
    printf("%d %d %d %d %d\n", array[0], array[1], array[2], array[3], array[4]); //debug
    array[NUM-1-i] = array[i]-array[NUM-1-i];
    printf("%d %d %d %d %d\n", array[0], array[1], array[2], array[3], array[4]); //debug
    array[i] = array[i]-array[NUM-1-i];
    printf("%d %d %d %d %d\n", array[0], array[1], array[2], array[3], array[4]); //debug
}

for (i=0; i<NUM; i++){
    printf("%d ", array[i]);
}

return 0;

}