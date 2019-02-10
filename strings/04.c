#include <stdio.h>
#include <string.h>

int main(){

    char string[50];

    printf("Insert a string:");

    fgets(string, sizeof(string), stdin);

    int i=0, j=(strlen(string)-1);

    printf("Sizeofstring: %d\n", j);

    printf("Stringa in ordine: %s", string);

    while (i<j) {
        char temp;
        temp = string[i];
        //printf("temp: %c = string[i](%d): %c \n", temp, i, string[i]);

        string[i] = string[j];
        //printf("string[i]: %c = string[j](%d): %c \n", string[i], j, string[j]);

        string[j] = temp;
        i++;
        j--;
    }

    printf("Stringa ordine inverso: %s", string);





    return 0;
}