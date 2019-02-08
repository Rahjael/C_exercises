#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <stdio.h>

int MenuSelect();
int RegisterNew();
int Delete();
int ShowStats();



int main(){

    int menuchoice;

    // Avvio del programma
    printf("Programma avviato.\n");
    printf("Benvenuto in FuelTracker.\n");
    printf("Carico il menu:\n");


    // Infinite loop per il menu

    int exit = 0;

    while (exit !=1){

        menuchoice = MenuSelect();
        
        switch (menuchoice){

            case 1: // nuovo inserimento
                RegisterNew();
                break;
            
            case 2: // cancella inserimento
                Delete();
                break;
            
            case 3: // mostra statistiche
                ShowStats();
                break;

            case 0: // Esci dal programma
                exit = 1;
                break;

            default:
                printf("\n\nScegli una voce del menu. Usa i numeri fra parentesi per selezionare le opzioni\n\n");
                break;


        }
    }


    printf("Esco dal programma.");
    return 0;
}




int MenuSelect(){

    int choice;
    
    printf("Inserisci un numero per decidere cosa fare:\n"

        "(1) Registra nuovo acquisto\n"
        "(2) Elimina un acquisto\n"
        "(3) Visualizza report globale\n"
        "(0) Esci\n"
    );

    scanf("%d", &choice);

    return choice;

}


int RegisterNew(){

    printf("BLABLABLA nuovo inserimento\n");
    printf("\n\n\n ritorno al menu dopo aver finito\n\n\n");

}


int Delete(){

    printf("BLABLABLA cancello inserimento\n");
    printf("\n\n\n ritorno al menu dopo aver finito\n\n\n");

}


int ShowStats(){

    printf("BLABLABLA mostro le statistiche \n");
    printf("\n\n\n ritorno al menu dopo aver finito\n\n\n");

}
