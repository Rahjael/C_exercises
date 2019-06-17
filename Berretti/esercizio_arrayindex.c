
/*

Scrivere la funzione C che riceve in ingresso una lista collegata con array ed indici di valori interi, un array V di
valori interi di dimensione N, ed usa gli elementi del vettore per popolare la lista. Gli elementi devono essere
copiati in modo da ottenere un inserimento ordinato nella lista.

*/

#include <stdlib.h>
#include <stdio.h>

#define LIST_SIZE 5

struct record
{
    int value;
    int next;
};

struct list
{
    struct record *buffer;
    int first;
    int free;
    int size;
};


void order_linked_list(struct list *ptr)
{
    /* si assume che la lista in ingresso sia così strutturata:

        struct list{
            int first;
            int free;
            int size;
            struct record * buffer;
        };

        dove

        struct record{
            int value;
            int next;
        };

    */

    // copio tutti i valori in un array di appoggio
    int temp_array[ptr->size];
    for (int i = 0; i < ptr->size; i++)
    {
        temp_array[i] = ptr->buffer[i].value;
    }

    // printo l'array di appoggio per verifica
    printf("\nValori copiati in array di appoggio: ");
    for (int i = 0; i < ptr->size; i++)
    {
        printf("%d ", temp_array[i]);
    }

    // ordino l'array di appoggio

    int *min;
    int temp;
    int i;
    int k;

    for (i = 0; i < ptr->size; i++)
    {
        min = &temp_array[i];

        for (k = i+1; k < ptr->size; k++){
            if (*min > temp_array[k]){
                min = &(temp_array[k]);
            }
        }

        temp = temp_array[i];
        temp_array[i] = *min;
        *min = temp;
    }

    // printo l'array di appoggio per verifica
    printf("\nArray di appoggio in ordine: ");
    for (int i = 0; i < ptr->size; i++)
    {
        printf("%d ", temp_array[i]);
    }

    // svuoto la lista originale e resetto gli indici
    ptr->first = ptr->size;
    ptr->free = 0;
    for (int i = 0; i < ptr->size; i++)
    {
        ptr->buffer[i].value = 0;
        ptr->buffer[i].next = i + 1;
    }

    // ripopolo la lista già ordinata

    int moved = ptr->free;
    ptr->first = 0;
    int *pos = &(ptr->first);

    for (int i = 0; i < ptr->size; i++)
    {
        ptr->buffer[*pos].value = temp_array[i];
        pos = &(ptr->buffer[*pos].next);
        ptr->free = ptr->buffer[*pos].next;
    }

    // stampo la lista per verifica

    printf("\nValori in ordine nello struct list: ");
    for (int i = 0; i < ptr->size; i++)
    {
        printf("%d ", ptr->buffer[i].value);
    }

    printf("\nPtr->free = %d", ptr->free);
}

int main()
{

    struct list *lista = (struct list *)malloc(sizeof(struct list));
    printf("\nstruct list creato");

    lista->buffer = (struct record *)malloc(LIST_SIZE * sizeof(struct record));

    lista->size = LIST_SIZE;
    lista->first = 0;
    lista->free = 0;
    for (int i = 0; i < lista->size; i++) // sistemo gli indici
    {
        lista->buffer[i].next = i + 1;
    }
    printf("\nindici sistemati");

    // chiedo all'utente 5 valori casuali e li metto nella lista (inserimento in coda)
    for (int i = 0; i < lista->size; i++)
    {
        int newvalue;
        printf("\nInserisci un nuovo valore per la lista: ");
        scanf(" %d", &newvalue);

        int * pos;
        int moved = lista->free;
        lista->free = lista->buffer[moved].next;

        pos = &(lista->first);
        while(*pos != lista->size)
        {
            pos = &(lista->buffer[*pos].next);
        }
        *pos = moved;
        lista->buffer[moved].value = newvalue;
        lista->buffer[moved].next = lista->size;

    }

    // stampo la lista
    printf("\nHai inserito i valori: ");
    int pos = lista->first;
    while (pos != lista->size)
    {
        printf("%d ", lista->buffer[pos].value);
        pos = lista->buffer[pos].next;
    }

    printf("\n______________\n");

    order_linked_list(lista);

    return 0;
}