
/*

22-02-17

Scrivere la funzione C che data una lista sequenziale ed una variabile intera ind, cancella dalla lista l’elemento
con scostamento ind relativo alla testa (cioè se ind=0 è cancellato l’elemento in testa alla lista). Ipotizzare che
gli elementi della lista siano di tipo struct record. Scrivere anche la funzione di costo e la complessità
dell’algoritmo.

struct record {
    float value;
    int code;
};

*/

#include <stdio.h>
#include <stdlib.h>

typedef unsigned short int boolean;

#define LIST_SIZE 5
#define TRUE 1
#define FALSE 0


struct record {
    float value;
    int code;
};

struct list {
    struct record * buffer;
    int head;
    int tail;
    int size;
};

boolean delete_item(struct list * ptr, int ind)
{
    
    int pos = ptr->head+ind;

    if(ptr->tail == ptr->head)
    {
        printf("\nList is empty, nothing to delete.");
        return FALSE;
    }
    else if ((ptr->head+pos)%ptr->size >= ptr->tail)
    {
        printf("\nOffseat overhead. There is no item at specified index");
        return FALSE;
    }
    else    
    {    
        do
        {
            ptr->buffer[pos] = ptr->buffer[((pos)+1)%ptr->size];
            pos = (pos+1)%ptr->size;
        }while(pos < ptr->tail);

        ptr->tail = (((ptr->tail)+ptr->size)-1)%ptr->size;
        printf("\nItem deleted");

        return TRUE;
    }
}

