#include <stdio.h>


/*
Write a program in C to count total number of vowel 
or consonant in a string.
*/

int main(){

    char parola[50];

    printf("Inserire una parola:\n");
    scanf("%s", parola);

    int vowels = 0;
    int consonants = 0;

    for (int i=0; parola[i] != '\0'; i++){

        if (parola[i] >= 65 && parola[i] <= 90 || parola[i] >= 97 && parola[i] <= 122){

            if (parola[i] == 65 ||
            parola[i] == 69 ||
            parola[i] == 73 ||
            parola[i] == 79 ||
            parola[i] == 85 ||
            parola[i] == 97 ||
            parola[i] == 101 ||
            parola[i] == 105 ||
            parola[i] == 111 ||
            parola[i] == 117)
            {
                vowels++;

            }
            else
            {
                consonants++;
            }
        }
        else
        {
            printf("Unexpected error.");
        }
        
    }

    printf("Vocali: %d\n", vowels);
    printf("Consonanti: %d\n", consonants);


    return 0;
}