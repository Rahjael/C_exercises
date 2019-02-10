#include <stdio.h>


int main(){

    char string[50];

    printf("Insert a string:");
    fgets(string, sizeof(string), stdin);

    printf("String: %s\n", string);

    int i=0;

    while (string[i] != '\0'){
        printf("%c ", string[i]);
        i++;

    }









    return 0;
}