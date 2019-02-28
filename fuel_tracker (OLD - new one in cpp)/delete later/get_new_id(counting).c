#include <stdio.h>
#include <string.h>

#define WHILE_OVERFLOW 150
#define DATABASE_NAME "mock_database.txt"

int main(){ // Rename: GetNewID()

    /*  
        Questa funzione conta le righe del database e genera un nuovo id
        che sarà <conteggio+1> da assegnare al nuovo record da generare.

        Siccome l'eliminazione dei singoli record con il tempo può interrompere 
        la progressività degli <id>, aggiungere un controllo automatico
        e fare in modo che ad ogni creazione di nuovo record tutti i precedenti 
        vengano controllati e rinumerati in caso di bisogno.
        Questo compito è affidato a OrderIds()

    */

    char string_buffer[100];

    unsigned int newid=0;

    short int failsafe=0;

    // OrderdIds();

    FILE * p_file;

    p_file = fopen(DATABASE_NAME, "r");

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
}
