#include <stdio.h>

int main() {

/*
Write a C program to calculate the average marks of mathematics of some students. 
Input 0 (excluding to calculate the average) or negative value to terminate the input process.
*/

float new_mark=1, total=0;

int marks=0;

while (new_mark !=0){
    printf("Insert mark (0 to end):\n");
    scanf("%f", &new_mark);
    if (new_mark !=0){
        total += new_mark;
        marks++;
        printf("%f", total);
    }
}

printf("Average mark: %f", total/marks);


return 0;

}