#include <stdio.h>


int CountString(char *);


int main(){

/*
Write a program in C to compare two string without 
using string library functions.
*/


    char string1[50], string2[50];

    printf("Inserire due stringhe:\n");
    scanf("%s", string1);
    scanf("%s", string2);

    int str_length1 = CountString(string1);
    int str_length2 = CountString(string2);


    if (str_length1 > str_length2){
        printf("string 1 is longer than string2: %d > %d", str_length1, str_length2);
    }
    else if (str_length1 < str_length2)
    {
        printf("string 2 is longer than string1: %d > %d", str_length2, str_length1);
    }
    else
    {
        printf("The strings are of equal length: %d = %d", str_length1, str_length2);
    }
    
    return 0;
}


int CountString(char * string){

    int count = 0;

    for (int i=0; string[i] != '\0'; i++){
        count++;
        printf("%s - Size of string: %d\n", string, count);
    }

    for (int i=0; i<10; i++){
        printf("String: %c\n", string[i]);
    }

    return count;
}