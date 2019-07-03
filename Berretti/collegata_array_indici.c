#include <stdio.h>
#include <stdlib.h>

typedef int Boolean;
#define TRUE 1
#define FALSE 0


struct record
{
    int value;
    int next;
};

struct list
{
    int size;
    int first;
    int free;
    struct record * buffer;
};

void initialise(struct list * list)
/* inizializza tutti i record con il valore di next */
{
    list->buffer = (struct record *)malloc(list->size * (sizeof(int)));
    list->free = 0;
    list->first = list->size;

    for(int i=0; i<list->size ; i++)
    {
        list->buffer[i].next = i+1;
    }
}

void print_list(struct list * list)
/* stampa il contenuto della lista */
{
    int offset = list->first;

    while(list->buffer[offset].next != list->size)
    {
        printf("%d ", list->buffer[offset].value);
        offset = list->buffer[offset].next;
    }
}

void pre_insert(struct list * list, int newvalue)
{
    if(list->free != list->size)
    {
        int tmp = list->first;
        list->first = list->free;
        list->free = list->buffer[list->free].next;
        list->buffer[list->first].next = tmp;
        list->buffer[list->first].value = newvalue;

    }
    else
    {
        printf("\nLista piena");
    }
}

void post_insert(struct list * list, int newvalue)
{
    int tmp;
    int * position;

    if(list->free != list->size)
    {
        tmp = list->free;
        
    }

}