#include <stdio.h>


int main(){

    char string[50];

    printf("Enter a string:");
    fgets(string, 50, stdin);

    printf("String: %s", string);

    int i = 0;
    while(string[i] != '\0'){
        i++;
    }

    printf("String length: %d", i-1);










    return 0;
}