#include <stdio.h>
#define NUM 5

/*
Write a C program that accepts some integers 
from the user and find the highest value 
and the input position
*/


int main() {

int number, array[NUM], max_value=0, max_position=0;


for (int i=0; i<NUM; i++){
    printf("Insert a number:");
    scanf("%d", &array[i]);
}

for (int i=0; i<NUM; i++){
    if (array[i] > max_value){
        max_value = array[i];
        max_position = i+1;
    }
}

printf("Max value is %d in position %d", max_value, max_position);

return 0;

}