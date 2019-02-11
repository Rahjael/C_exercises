#include <stdio.h>


// Per ogni n < y visualizza tutti gli n che finiscono per x




int main(){

    int n=0, n_alt, x, y, x_alt, pos_decimal=0, modulo=1;

    printf("Insert upper limit:\n");
    scanf("%d", &y);

    printf("\nInsert number to compare:\n");
    scanf("%d", &x);

    // copio le variabili per manipolarle
    x_alt = x;



    // Determina di quante posizioni decimali è composto x

    while (x_alt != 0){ 

        x_alt /= 10; // Scarto l'ultima cifra (aka: mi sposto a sinistra a partire dalle unità)
        pos_decimal++; // Conto di quanti posti mi muovo

    }

    // imposto il modulo per estrarre le cifre finali:

    for (int i=0; i<pos_decimal; i++){
        modulo *= 10; // Mi muovo per potenze di 10
    }


    // Per ogni n <= y controllo se n deve essere printato:


    printf("\nPrinto i numeri validi che terminano per X = %d, fino a Y = %d\n\n", x, y);

    while(n <= y){

        n_alt = n;

        n_alt %= modulo; // Estraggo le ultime cifre richieste

        // Verifico il numero e lo printo
        
        if (n_alt == x){
            printf("Numero valido: %d\n", n); // printo n per intero, se finisce per il numero x
        }

        n++; // Passo al numero successivo

    }



    return 0;
}