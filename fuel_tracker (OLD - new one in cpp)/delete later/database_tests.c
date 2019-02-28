#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

/* STRUTTURA DATABASE

<ID>,<modello_auto>,<prezzo_rifornimento>,<km>,<data>

<id> = identificativo del record. Di fatto è il numero della riga nel file
<modello_auto> = identificativo del mezzo con il suo nome.
<prezzo_rifornimento> = la cifra spesa per fare benzina in quel record
<km> = i km totali del mezzo al momento di quel rifornimento
<data> = la data di quel rifornimento

I valori sono separati da ','

Ogni riga è interrotta da '\n'

*/

int NewRecord();


int main(){



    return 0;
}


int NewRecord(){

    // Get new <id> number:



    printf("\nStai inserendo un nuovo record.\n");
    printf("Inserisci")





    return 0;
}


int GetNewIdNumber(){

    char line[100] = {0};

    int newid;

    FILE * p_file;

    p_file = fopen("mock_database.txt", "r");

    for (; gets(p_file) != EOF;){
        fgets(line, sizeof(line), p_file);

    }

    newid = line[0];

    fclose(p_file);

    printf("%d", newid);

    return newid;
}