#include <stdio.h>
#include <string.h>

#define WHILE_OVERFLOW 150
#define DATABASE_NAME "mock_database2.txt"

int main(){ // Rename: OrderIds()

    /*  
        Questa funzione controlla tutti i numeri di riga del database
        e verifica che siano in ordine.

        Se non sono in ordine li riassegna.

    */

    char string_buffer[100];

    unsigned int line_count=1;

    short int failsafe=0;

    FILE * p_file;

    p_file = fopen(DATABASE_NAME, "w");

    printf("Inserire una stringa da aggiungere al file:\n");
    fgets(string_buffer, sizeof(string_buffer), stdin);

    fprintf(string_buffer, "%s", string_buffer);

    printf("Size of buffer: %d : %s", strlen(string_buffer), string_buffer);
















/*
    while(1){

        // Failsafe for debugging purposes - delete in final version?
        failsafe++;
        if (failsafe >= WHILE_OVERFLOW){
            printf("While overflow. Exit.");
            break;
        }
        // End failsafe

        fgets(string_buffer, sizeof(string_buffer), p_file); // Prendo la riga e la butto nel buffer

        printf("%s\n", string_buffer); // Debug

        newid++; // Tiene il conto delle righe nel file

        if ( feof(p_file) ){ 
            printf("End of file found. Exit.\n"); // Debug
            break;
        }

    }
   

    fclose(p_file);

    printf("Last id: %d\n", newid); // Debug
    newid++;
    printf("New id: %d\n", newid); // Debug

    return newid;

    */

   return 0;
}
