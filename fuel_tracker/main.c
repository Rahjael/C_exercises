#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <stdio.h>

int MenuSelect();
int NewRecord(int);
int DeleteRecord(int);
int ShowStats(in);



int main(){

    int menuchoice;

    printf("Programma avviato.\n");
    printf("Benvenuto in FuelTracker.\n");
    printf("Carico il menu:\n");

    menuchoice = MenuSelect();
    
    switch (menuchoice)


    return 0;
}

int MenuSelect(){

    printf("Inserisci un numero per decidere cosa fare:\n"

        "(1) Registra nuovo acquisto\n"
        "(2) Elimina un acquisto\n"
        "(3) Visualizza report globale\n"
    );

    scanf("%d", &choice);

    return choice;

}



