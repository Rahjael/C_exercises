/*

    ESERCIZIO:

    Crea un programma che:

    - crea una lista con circular buffer di size SIZE;
    - aggiunge X valori random in coda;
    - aggiunge Y valori random in testa;
    - stampa tutti i valori;
    - li rimette in ordine;
    - ristampa la lista in ordine;


*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MIN 0       // min range        //
#define MAX 1000    // max range        // these values configure the random int generator


#define SIZE 20             // set the size for circular buffer
#define TAIL_TO_ADD 6       // set the numbers to add to list after initialization
#define HEAD_TO_ADD 8       // set the numbers to add to head

//
//
// COMMON FUNCTIONS
//
//

int get_random_number(int min, int max)
{
    int num;
    num = (rand() % (max - min)) + min;
    return num;
}

///////////////////////// END OF COMMON FUNCTIONS

struct list
{
    int * buffer;
    int size;
    int head;
    int tail;
};

void init_list(struct list * list)
{
    list->buffer = (int *)malloc(sizeof(int) * list->size);
    list->head = 0;
    list->tail = 0;

    printf("\nList initialized.");
}

void tail_add_random(struct list * list)
{
    if((list->tail+1)%(list->size) != list->head)
    {
        list->buffer[list->tail] = get_random_number(MIN, MAX);
        list->tail = (list->tail+1) % list->size;
    }
    else
    {
        printf("\nList is full! Unable to add further numbers");
    }    
}

void head_add_random(struct list * list)
{
    if((list->tail+1) % list->size != list->head)
    {
        list->head = (list->head + list->size - 1) % list->size;
        list->buffer[list->head] = get_random_number(MIN, MAX);
    }
    else
    {
        printf("\nList is full! Unable to add further numbers");
    }
}

void print_list_values(struct list * list)
{
    for(int i = list->head; i != list->tail; i = (i+1) % list->size)
    {
        printf("%d ", list->buffer[i]);
    }
}








int main()
{
    // Setta il seed per il generatore random
    srand(time(0));

    // Crea la struttura per il circular buffer
    struct list list;
    list.size = SIZE;

    init_list(&list);

    populate_list(&list);




    return 0;
}