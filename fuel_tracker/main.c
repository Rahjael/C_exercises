#include <stdio.h>
#include <string.h>

#define DATABASE_NAME "database" // Nome del file database (binary)
#define CONFIG_FILE "config" // Nome del file config (binary)
#define TEMP_STORAGE "temp_storage" // Nome del file temp (binary)


// Dichiaro la struttura dei record nel database:

struct Record {

    unsigned int id; 
    char vehicle[15];
    float amount;
    unsigned int km;
    
};

// Dichiaro la struttura del file config

/*
    Nel file config vengono salvate tutte le variabili accessorie
    che non sono parte del database vero e proprio e mi fa comodo
    averle indipendenti e accessibili senza incasinare la struttura
    del database.
*/

struct Config {

    char last_vehicle[15];

};

// Function declarations

int CountDatabaseEntries(void); // Restituisce un int con il numero di record nel database
void StartupChecks(void); // Controlla l'esistenza dei file database e config
void InsertNewRecord(void); // Chiede all'utente i dati del nuovo record
void InsertNewRecord_Append(struct Record); // Salva nel database il nuovo record, se l'utente conferma
int InsertNewRecord_CheckVehicle(char string[15]); // Controlla se il veicolo è nuovo o scritto male
void MainMenu(void); // Mostra il menu principale
void ShowEntireDatabase(void); // Mostra tutte le voci del database
void DeleteRecord(int id); // Elimina dal database la voce selezionata


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

    StartupChecks();
    printf("Sono presenti %d record\n", CountDatabaseEntries());

    printf("\n\n### Carico il menu:\n\n");

    MainMenu();

    return 0;
}


/*


    FUNCIONS DEFINITIONS


*/

void StartupChecks(void){

    /*
        Checks database and config files

    */

    // Check config file

    FILE * p_config;

    if(fopen(CONFIG_FILE, "rb")){
        printf("\n### File di configurazione rilevato.\n");
    }
    else
    {
        printf("\n### File di configurazione non trovato.\n");
        printf("### Creo il file di configurazione.\n");

        p_config = fopen(CONFIG_FILE, "wb"); // Creo il file

        struct Config config;

        strcpy(config.last_vehicle, "first_run");
        printf("### File di configurazione creato.\n");

        printf("\n### Debug: %s\n\n", config.last_vehicle);

        fwrite(&config, sizeof(struct Config), 1, p_config);

        fclose(p_config);
    }
    


    // Checks if database exists. If it doesn't, create it.


    FILE * p_database;

    if(!(p_database = fopen(DATABASE_NAME, "rb"))){
        
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

int CountDatabaseEntries(void){

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

void InsertNewRecord(void){

    /*

        Get data from user input and append to database

    */

    struct Record new_record;
    struct Config config;

    char confirm_vehicle;
    char use_last;

    // Carico il file config e lo metto nello (struct Config) config
    FILE * p_config = fopen(CONFIG_FILE, "rb"); // Apro lo stream
    fread(&config, sizeof(struct Config), 1, p_config); // Lo salvo nella variabile struct
    fclose(p_config); // Chiudo lo stream

    // Set new record ID
    new_record.id = CountDatabaseEntries()+1;

    // Ask user for data
    do{

        // Check if first use
        if (strcmp(config.last_vehicle, "first_run") == 0){
            use_last = 'n';
        }
        else{
            // Ask if same vehicle as lasta time, else use new name
            printf("Ultimo veicolo registrato: %s. Usare? (s, n)\n", config.last_vehicle);
            scanf(" %c", &use_last);
        }

        switch (use_last){

            case 's':
                strcpy(new_record.vehicle, config.last_vehicle);
                break;

            case 'n':

                do {

                    printf("Inserisci il nome del veicolo (max 15 caratteri):\n");
                    scanf(" %s", new_record.vehicle);

                    // Check if vehicle already exists
                    int is_new = InsertNewRecord_CheckVehicle(new_record.vehicle);

                    if (is_new == 1){
                        printf("\n### ATTENZIONE: \n"
                            "### Il nome che hai inserito non corrisponde a nessun veicolo presente nel database. \n"
                            "### Si tratta di un nuovo inserimento o è stato scritto male il nome?\n"
                            "\n\t Nome inserito: %s\n\n", new_record.vehicle);

                            printf("Confermi il nome inserito? (s, n)\n");
                            scanf(" %c", &confirm_vehicle);
                    }
                    else
                    {
                        confirm_vehicle = 's';
                        printf("\n%s già presente nel database. Confermato.\n", new_record.vehicle);
                    }
                    

                }while( confirm_vehicle != 's');

                break;

            default:
                printf("### Non ho capito la risposta.\n");
        }

    }while (use_last != 's' && use_last !='n');

    printf("Inserisci il costo del rifornimento:\n");
    scanf(" %f", &new_record.amount);
    printf("Inserisci km attuali del veicolo:\n");
    scanf(" %u", &new_record.km);

    char ans;

    do{
        printf("\n\nHai inserito i seguenti dati:\n");
        printf("ID: %u\n", new_record.id);
        printf("Veicolo: %s\n", new_record.vehicle);
        printf("Spesa: %.3f\n", new_record.amount);
        printf("Km attuali: %u\n\n", new_record.km);

        printf("I dati sono corretti? (s) per confermare, (n) per annullare.\n");


        scanf(" %c", &ans);

        switch (ans){

            case 's': 

                // Salvo nel config il veicolo per proporlo al prossimo inserimento
                strcpy(config.last_vehicle, new_record.vehicle);                
                FILE * p_config = fopen(CONFIG_FILE, "wb");
                fwrite(&config, sizeof(struct Config), 1, p_config);
                fclose(p_config);

                // Salvo nel database i dati inseriti dall'utente
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

void InsertNewRecord_Append(struct Record to_be_stored){

    /*
        This function is called by InsertNewRecord() after the user confirms data.
        It collects data and writes it to the database.
    */


    FILE * p_buffer = fopen(DATABASE_NAME, "ab");

    fwrite(&to_be_stored, sizeof(struct Record), 1, p_buffer);

    fclose(p_buffer);

    printf("\n\n### Ho inserito i dati.\n");

    printf("\n### Rileggo i dati per debug:\n");

    ShowEntireDatabase();

}

void MainMenu(void){

    /*
        Main Menu. The entire program basically runs inside this funcion until
        user exits (0).

    */

    int menuchoice=1;
    
    // Infinite loop for the menu

    while (menuchoice !=0){

        printf("Inserisci un numero per selezionare la corrispondente voce del menu:\n"

        "(1) Registra nuovo acquisto\n"
        "(2) Elimina un acquisto (NON IMPLEMENTATO)\n"
        "(3) Visualizza database\n"
        "(0) Esci\n"
        );

        scanf(" %d", &menuchoice);

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

void ShowEntireDatabase(void){

    /*
        Reads from the database and shows every record in it
    */

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
            // Prendo il carattere successivo per vedere se mi aspetta EOF
            c = fgetc(p_file);
            // Risposto il cursore indietro di un char (1 byte)
            fseek(p_file, -1, SEEK_CUR);

            printf("ID: %u \tVeicolo: %s \tSpesa: %.3f \tKm: %u\n", temp_record.id, temp_record.vehicle, temp_record.amount, temp_record.km);
        }
        
    } while (c != EOF); // Verifico se il carattere che ho preso prima è un EOF

    fclose(p_file);

    printf("\n\n### Database visualizzato per intero. Sono presenti %d record.\n\n", CountDatabaseEntries());


}

int InsertNewRecord_CheckVehicle(char vehicle_to_check[15]){

    struct Record record;
    int is_new = 0;
    char c;

    //printf("\n### Debug - Vehicle to check: %s\n", vehicle_to_check);

    FILE * p_buffer = fopen(DATABASE_NAME, "rb");

    do{
        fread(&record, sizeof(struct Record), 1, p_buffer);
        c = fgetc(p_buffer); // Prendo il carattere per la verifica del fine stream
        fseek(p_buffer, -1, SEEK_CUR); // Mando indietro il cursore di 1 byte

        if (strcmp(vehicle_to_check, record.vehicle) == 0){
            is_new = 0;
            break;
        }
        else
        {
            is_new = 1;
        }
        
    }while(c != EOF);

    fclose(p_buffer);

    return is_new;

}


void DeleteRecord(int id){

    struct Record temp_record; // Creo il temp_record in cui mettere i dati estratti dal database
    unsigned int choice;
    int count=0;

    ShowEntireDatabase();

    printf("Quale record vuoi eliminare? (Inserisci il numero ID)\n");
    scanf(" %d", &choice);

    FILE * p_buffer = fopen(DATABASE_NAME, "r+b");

    // Trova il record da eliminare e conta quanti record
    do{
        fread(&temp_record, sizeof(struct Record), 1, p_buffer);
        count++;
    } while (temp_record.id != choice);

    fclose(p_buffer);











}