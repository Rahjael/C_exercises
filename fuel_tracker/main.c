#include <stdio.h>
#include <string.h>

#define DATABASE_NAME "database" // Nome del file database (binary)


// Dichiaro la struttura dei record nel database:

struct Record {

    unsigned int id; 
    char vehicle[15];
    float amount;
    unsigned int km;
    
};


// Function declarations

int CountDatabaseEntries();
void CheckDatabaseExists();
void InsertNewRecord();
int InsertNewRecord_Append(struct Record);
void MainMenu();
void ShowEntireDatabase();


// Main program

int main(){
    
    /*
    // Populate database with some stuff for test purposes
    
    struct Record uno = {1, "Punto", 12.439, 12349322};
    struct Record due = {2, "Panda", 23.234, 4502};

    FILE * p_populate = fopen(DATABASE_NAME, "wb");

    fwrite(&uno, sizeof(struct Record), 1, p_populate);
    fwrite(&due, sizeof(struct Record), 1, p_populate);
    fclose(p_populate);
    
    */


    // Avvio del programma
    printf("\n\n\nProgramma avviato.\n\n");
    printf("\nBenvenuto in FuelTracker.\n\n");

    CheckDatabaseExists();
    printf("Sono presenti %d record\n", CountDatabaseEntries());

    printf("\n\n### Carico il menu:\n\n");

    MainMenu();

    return 0;
}


/*


    FUNCIONS DEFINITIONS


*/

void CheckDatabaseExists(){
    /*
    
        Checks if database exists. If it doesn't, create it.

    */

    FILE * p_database;

    if(!(p_database = fopen(DATABASE_NAME, "r"))){
        
        printf("### Database inesistente. Lo creo.\n");
        
        fopen(DATABASE_NAME, "wb");
        
        printf("### Database creato.\n");
    }
    else
    {
        printf("### Database rilevato.\n");
    }
    
    fclose(p_database);

}

int CountDatabaseEntries(){

    /*

        Counts the number of records in the database

    */

    int entries=0;
    char c;
    struct Record temp_record;

    FILE * p_file;

    p_file = fopen(DATABASE_NAME, "rb");

    do {
        // Verifico che fread non sia NULL
        if(fread(&temp_record, sizeof(struct Record), 1, p_file)){
            entries++;
        }
        // Prendo il carattere successivo per la verifica
        c = fgetc(p_file);
        // Risposto il cursore indietro di un char (1 byte)
        fseek(p_file, -1, SEEK_CUR);

    } while (c != EOF); // Verifico se il carattere che ho preso prima è un EOF

    fclose(p_file);

    return entries;

}

void InsertNewRecord(){

    /*

        Get data from user input and append to database

    */

    struct Record new_record;

    char ans;

    // Set new record ID
    new_record.id = CountDatabaseEntries()+1;


    // Ask user for data
    printf("Inserisci il nome del veicolo (max 15 caratteri):\n");
    scanf("%s", &new_record.vehicle);
    printf("Inserisci il costo del rifornimento:\n");
    scanf("%f", &new_record.amount);
    printf("Inserisci km attuali del veicolo:\n");
    scanf("%u", &new_record.km);

    do{
        printf("\n\nHai inserito i seguenti dati:\n");
        printf("ID: %u\n", new_record.id);
        printf("Veicolo: %s\n", new_record.vehicle);
        printf("Spesa: %.3f\n", new_record.amount);
        printf("Km attuali: %u\n\n", new_record.km);

        printf("I dati sono corretti? (s) per confermare, (n) per annullare.\n");


        scanf("%c", &ans);

        switch (ans){

            case 's': 
                InsertNewRecord_Append(new_record);
                break;                

            case 'n':
                printf("\n### Inserimento annullato. Torno al menu principale.\n");
                MainMenu();
                break;

            default:
                printf("### Non ho capito la risposta.\n");
                printf("### Digita (s) per confermare, (n) per annullare.\n");

        }
        
    }while (ans != 's' && ans != 'n');


}

int InsertNewRecord_Append(struct Record to_be_stored){

    FILE * p_buffer = fopen(DATABASE_NAME, "ab");

    fwrite(&to_be_stored, sizeof(struct Record), 1, p_buffer);

    fclose(p_buffer);

    printf("\n\n### Ho inserito i dati.\n");

    printf("\n### Rileggo i dati per debug:\n");

    ShowEntireDatabase();

}

void MainMenu(){

    int menuchoice=1;
    
    // Infinite loop per il menu

    while (menuchoice !=0){

        printf("Inserisci un numero per selezionare la corrispondente voce del menu:\n"

        "(1) Registra nuovo acquisto\n"
        "(2) Elimina un acquisto\n"
        "(3) Visualizza report globale\n"
        "(0) Esci\n"
        );

        scanf("%d", &menuchoice);

        switch (menuchoice){

            case 1: // nuovo inserimento
                InsertNewRecord();
                break;
            
            case 2: // cancella inserimento
                //Delete();
                break;
            
            case 3: // mostra statistiche
                ShowEntireDatabase();
                break;

            case 0: // Esci dal programma
                menuchoice = 0;
                printf("\n### Esco dal programma.\n");
                break;

            default:
                printf("\n\nScegli una voce del menu. Usa i numeri fra parentesi per selezionare le opzioni\n\n");
                break;
        }
    }
}

void ShowEntireDatabase(){

    char c;
    
    struct Record temp_record;

    FILE * p_file;

    p_file = fopen(DATABASE_NAME, "rb");

    do {

        // Verifico se il database è vuoto

        if ((c = fgetc(p_file)) == EOF){
            printf("\nIl database è vuoto.\n");
        }
        else{
            // Risposto il cursore indietro di un char (1 byte)
            fseek(p_file, -1, SEEK_CUR);

            // Leggo il chunk di dati per struct Record
            fread(&temp_record, sizeof(struct Record), 1, p_file);

            // Prendo il carattere successivo per la verifica
            c = fgetc(p_file);

            // Risposto il cursore indietro di un char (1 byte)
            fseek(p_file, -1, SEEK_CUR);

            printf("ID: %u \tVeicolo: %s \tSpesa: %.3f \tKm: %u\n", temp_record.id, temp_record.vehicle, temp_record.amount, temp_record.km);
        }
        
    } while (c != EOF); // Verifico se il carattere che ho preso prima è un EOF

    fclose(p_file);

    printf("\n\n### Database visualizzato per intero. Sono presenti %d record.\n\n", CountDatabaseEntries());


}