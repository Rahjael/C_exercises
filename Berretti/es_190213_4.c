
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
    Ad ogni ciclo invertono i rispettivi valori e si muovono entrambi verso il centro.
    Quando counter raggiunge (size/2) vuol dire che sono al centro della lista, e ho swappato tutti i valori
    
     */

    while (counter < (list->size/2)) // fino a che non raggiungo il centro della lista
    {
        while(list->buffer[(list->buffer[penultimate_index].next)].next != list->size)
        {
            // tutta la guardia del while mi serve per fermarmi al penultimo elemento
            penultimate_index = list->buffer[penultimate_index].next;
        }
        // a questo punto penultimate_index dovrebbe essere l'indice del penultimo elemento

        // swap values
        // salvo il valore del primo elemento in temp
        temp = list->buffer[head_index].value;

        // metto il valore dell'ultimo elemento nel primo elemento
        list->buffer[head_index].value = list->buffer[(list->buffer[penultimate_index].next)].value;
        
        // metto il valore di temp nell'ultimo elemento
        list->buffer[(list->buffer[penultimate_index].next)].value = temp;
        // fine swap values


        // cambia indici
        // cambio il next dell'ultimo elemento per farlo puntare al penultimo (inverto l'ordine)
        list->buffer[(list->buffer[penultimate_index].next)].next = penultimate_index;

        // setto come ultimo il penultimo elemento
        list->buffer[penultimate_index].next = list->size;

        // faccio avanzare l'indice head all'elemento successivo
        head_index = list->buffer[head_index].next;

        // riporto penultimate_index al pari di head
        penultimate_index = head_index;

        // se è la prima iterazione, cambio list->first con l'indice dell'ultimo elemento
        if(counter == 0)
        {
            list->first = list->buffer[penultimate_index].next;
        }

        counter++; // aumento counter per capire dove sono
    }

    // torno all'ex primo elemento (che ora è ultimo) e gli do il next appropriato
    list->buffer[original_first].next = list->size;

}



