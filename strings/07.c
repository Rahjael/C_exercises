#include <stdio.h>

/*
Write a program in C to count total number of 
alphabets, digits and special characters in a string.
*/

int CountStuff(char * string, int * ptr_alpha, int * ptr_digit, int * ptr_special){


    for (int i=0; string[i]!= '\0'; i++){
        
        if (string[i] >= 65 && string[i] <= 90 || string[i] >= 97 && string[i] <= 122){
            (*ptr_alpha)++;
        }
        else if (string[i] >= 48 && string[i] <= 57){
            (*ptr_digit)++;
        }
        else if (string[i] >= 32 && string[i] <= 47 || string[i] >= 58 && string[i] <= 64 || string[i] >= 91 && string[i] <= 96 || string[i] >= 123 && string[i] <= 126){
            (*ptr_special)++;
        }
        else
        {
            printf("Carattere non riconosciuto. Errore.");
            return -1;
        }
        
    }

    return 0;
}

int main(){

    char string[50];

    int alpha = 0;
    int digit = 0;
    int special = 0;

    int * ptr_alpha = &alpha;
    int * ptr_digit = &digit;
    int * ptr_special = &special;


    printf("Inserisci una stringa:");
    gets(string);

    int esito = CountStuff(string, &alpha, &digit, &special);

    if (esito == 0){
        printf("\n\nConteggio completato.\n\n");
        
        printf("Stringa inserita: %s\n", string);
        printf("Alfabetici: %d\n", alpha);
        printf("Numerici: %d\n", digit);
        printf("Special: %d\n", special);

    }
    else if (esito == -1){
        printf("Errore nel conteggio");
    }
    else
    {
        printf("Unexpected error:");
    }
    
    return 0;
}