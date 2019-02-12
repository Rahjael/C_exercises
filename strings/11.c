#include <stdio.h>

/*
Write a C program to sort a string array in ascending order.
*/


int main(){


    char string[50], temp;

    int done=0;

    printf("Inserisci una stringa:\n");
    fgets(string, sizeof(string), stdin);

    while (1){
        
        done = 1;

        for (int i=0; string[i+2] != 0; i++){

            if(string[i] > string[i+1]){

                // swappa le variabili se i > i+1

                temp = string[i+1];
                string[i+1] = string[i];
                string[i] = temp;
                done = 0;
            }

            printf("%s\n", string);

        }

        if (done == 1) { // niente è cambiato in questo giro: array in ordine, esci.
            break;
        }

    }

    printf("\nOrdinamento completato.\n");

    return 0;
}