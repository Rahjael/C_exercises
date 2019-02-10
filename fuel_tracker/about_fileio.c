#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

/* STRUTTURA DATABASE

<ID>, <modello_auto>, <prezzo_rifornimento>, <km>, <data>

<id> = identificativo del record. Di fatto è il numero della riga nel file
<modello_auto> = identificativo del mezzo con il suo nome.
<prezzo_rifornimento> = la cifra spesa per fare benzina in quel record
<km> = i km totali del mezzo al momento di quel rifornimento
<data> = la data di quel rifornimento

I valori sono separati da ','

Ogni riga è interrotta da '\n'


*/


void DatabaseCheck();
void Separatori();
void PrintEntireDatabase();



int main(){


    FILE * ptr_database;

    // Create file

/*

    FILE * file_pointer;


    char stuff[50] = {1};

    int index;

    file_pointer = fopen("fuel_database.txt", "w"); // create/open file

    strcpy(stuff, "Esempio blablabla");

    for (int i=1; i<10; i++) {
        fprintf(file_pointer, "%s Line number %d\n", stuff, i);
    }

    fclose(file_pointer); // close file


*/



/*
    printf("\n\nSize of stuff: %d\n\n", sizeof(stuff));
    printf("\nSize of char %d\n", sizeof(char));
    printf("Sizeof(char) * 50: %d", sizeof(char)*50);
    printf("\nSize of stuff in bytes: %d\n\n", (sizeof(stuff)*(sizeof(char))));



    for (int k=0; k<50; k++){
        printf("%c", stuff[k]);
    }
*/


    DatabaseCheck();

    PrintEntireDatabase();

    return 0;

}


    // Read file


void DatabaseCheck(){

    /* Questa funzione in realtà non serve a molto, ma l'ho messa
    per fare un fileread */

    FILE * ptr_database; // Lo metto qui o nel main? Unsure.

    // Check if database exists:

    ptr_database = fopen("database.txt", "r");

    if (ptr_database == NULL)
    {

        Separatori();
        printf("### File database.txt non trovato! Primo avvio?\n");
        Separatori();
        fclose(ptr_database);
        printf("### Creo database\n");

        ptr_database = fopen("database.txt", "w");

        fclose(ptr_database);

        Separatori();
        printf("### Database creato\n");

    }
    else
    {
        Separatori();
        printf("### File database.txt trovato.\n");
        Separatori();

    }
    

    fclose(ptr_database);

    printf("\n\n\n");

    printf("\nFine di DatabaseCheck()\n");


}


void PrintEntireDatabase(){


    /* Riassume la situazione del database, stampandolo a video riga per riga
    */

    FILE * ptr_database; 

    ptr_database = fopen("mock_database.txt", "r");

    char buffer[100];

    int i=0;

    printf("Il database contiene i seguenti record:\n\n");

    do {

        fgets(buffer, sizeof(buffer), ptr_database);

        printf("%s\n", buffer);
        

    } while ( fgetc(ptr_database) != EOF);


}




void Separatori(){
    printf("###\n###\n###\n");
}



