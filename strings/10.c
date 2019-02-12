#include <stdio.h>

/*
Write a program in C to find maximum occurring character in a string.
*/


int main(){

    char string[100];

    char temp, max_char;

    int count=0, max_times=0;


    printf("Inserire una stringa:\n");
    fgets(string, sizeof(string), stdin);

    for (int i=0; string[i] != '\0'; i++){

        temp = string[i];
        printf("inizio for\n");

        for(int k=0; string[k] != '\0'; k++){
            if (temp == string[k]){
                count++;
                printf("\ncount increased. string[k]= %c\n", string[k]);
            }
        }

        printf("\nfor interno\n");

        if ( count > max_times){
            max_times = count;
            max_char = temp;
        }

    }

    printf("\nMost recurring letter is %c, repeating %d times\n", max_char, max_times);







    return 0;
}