
/*
Esercizio 4. (7 punti)
Scrivere la funzione C che riceve in ingresso una lista collegata con array ed indici di valori interi ed inverte
l’ordine degli elementi. L’inversione deve avvenire spostando i record degli elementi della lista. Scrivere anche
l’equazione di costo e la complessità dell’algoritmo. (Nota: supponendo che gli elementi della lista iniziale siano
L={5,3,7,2} la lista deve essere invertita come L={2,7,3,5}).

*/

#include <stdlib.h>

// si assume la seguente struttura dati

struct record
{
    int value;
    int next;
};

struct list
{
    struct record * buffer;
    int first;
    int free;
    int size;
};

// esercizio

void reverse_records(struct list * list)
{
    int counter = 0; // counter che mi serve per capire quando fermarmi
    int head_index = list->first; // indice per muovermi dalla cima
    int penultimate_index = head_index; // indice per trovare ultimo e penultimo elemento
    int temp; // temp per gli swap dei valori
    int original_first = list->first; // salvo il first originale perché mi servirà alla fine

    /*

    La logica funziona così:

    Ho due indici che partono da posizioni opposte.
    Ad ogni ciclo si muovono entrambi verso il centro.
    Quando counter raggiunge (size/2) vuol dire che sono al centro della lista, e ho swappato tutti gli indici
    
     */

    while (counter < (list->size/2)) // fino a che non raggiungo il centro della lista
    {
        while(list->buffer[(list->buffer[penultimate_index].next)].next != list->size)
        {
            // tutta la guardia del while mi serve per fermarmi al penultimo elemento
            penultimate_index = list->buffer[penultimate_index].next;
        }
        // a questo punto penultimate_index dovrebbe essere l'indice del penultimo elemento

        // cambio gli indici
        // se è la prima iterazione, cambio list->first con l'indice dell'ultimo elemento che adesso è primo
        if(counter == 0)
        {
            list->first = list->buffer[penultimate_index].next;
        }
        
        list->buffer[(list->buffer[penultimate_index].next)].next = penultimate_index; // cambio il next dell'ultimo elemento per farlo puntare al penultimo (inverto l'ordine)
        list->buffer[penultimate_index].next = list->size; // setto come ultimo il penultimo elemento
        head_index = list->buffer[head_index].next; // faccio avanzare l'indice head all'elemento successivo
        penultimate_index = head_index; // riporto penultimate_index al pari di head

        counter++; // aumento counter per capire dove sono
    }

    // torno all'ex primo elemento (che ora è ultimo) e gli do il next appropriato per segnalare il fine lista
    list->buffer[original_first].next = list->size;

}


// fine esercizio


