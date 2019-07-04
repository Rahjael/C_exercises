
/*
Esercizio 4. (6 punti)
Scrivere la funzione C che riceve in ingresso una lista sequenziale di valori di tipo int e li ordina con l’algoritmo
selection sort. Scrivere anche l’equazione di costo e la complessità dell’algoritmo.
 */


#include <stdlib.h>


// struttura per la lista sequenziale (si suppone già presente nel programma)
// è da considerarsi un circular buffer

struct list
{
    int * buffer;
    int size;
    int head;
    int tail;
};


void exercise_function(struct list * list)
// in questi esercizi il prof mette sempre SIZE tra i parametri formali
// ma secondo me non ha senso perché il size fa già parte degli elementi dello struct
{

    // alloco quello che mi serve
    int selected;
    int comparing;
    int temp;
    
    int * min; 

    // inizio il sorting
    for(selected = list->head; selected != list->tail; selected = (selected + 1) % list->size) // ciclo su tutti gli indici del buffer
    {
        min = &(list->buffer[selected]); // prendo l'elemento corrente e lo considero il minimo

        // cicla internamente per comparare gli elementi
        // il buffer è circolare quindi c'è il cazzo in culo di ricordarsi che FA IL GIRO DEA RODA
        for(comparing = (selected+1) % list->size; comparing != list->tail; comparing = (comparing + 1) % list->size)
        {
            if(list->buffer[comparing] < *min)
                min = &(list->buffer[comparing]); // ogni minimo che trova lo punta
        }

        // a fine ciclo swappo i valori
        temp = list->buffer[selected];
        list->buffer[selected] = *min;
        *min = temp;
    }
}



/* FUNZIONE DI COSTO

    Non ho ancora capito bene come si calcola con precisione questa cosa.

    Contando riga per riga però secondo me il discorso è:

    30. 1
    31. 1
    32. 1

    34. 1

        inizio for esterno -> worst case N-1 iterazioni
    39. 1
        inizio for interno -> worst case N/2 iterazioni
    46. 1

        fine for interno
    50. 1
    51. 1
    52. 1


    Quindi dovrebbe venire 3(n-1)(n/2)+4
                        = 3((n^2-n)/2)+4 ??? Boh.

 */