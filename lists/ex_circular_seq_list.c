#include <stdio.h>
#include <stdlib.h>

/*
ESERCIZIO:

Creare una lista circolare di valori float che abbia le seguenti funzioni:

- inizializza lista di dimensioni n definite dall'utente
- stampa intera lista
- aggiungi elemento in coda
- aggiungi elemento in testa
- elimina elemento in coda
- elimina elemento in testa

*/


struct list {
    float * p_buffer;
    int size;
    int head;
    int tail;
};


void init_list(struct list * p_list/*, int size*/){

    p_list->p_buffer = (float *)calloc(p_list->size, (p_list->size)*sizeof(float));
    p_list->head = 0;
    p_list->tail = 0;
    //p_list->size = size;
    printf("\nLista inizializzata.\n");

}

int insert_tail(struct list * p_list, float value){

    if (((p_list->tail+1)%p_list->size) != p_list->head)
    {
        p_list->p_buffer[p_list->tail] = value;
        p_list->tail=(p_list->tail+1)%p_list->size;
        return 0;
    }
    else
    {
        return 1;
    }
}
    

int insert_head(struct list * p_list, float value){

    if (((p_list->tail+1)%p_list->size) != p_list->head)
    {
        p_list->head = (p_list->head + p_list->size - 1)%p_list->size;
        p_list->p_buffer[p_list->head] = value;
        return 0;
    }
    else
    {
        return 1;
    }
}

int delete_head(struct list * p_list){

    if ((p_list->head+1)%p_list->size != p_list->tail)
    {
        p_list->p_buffer[p_list->head] = 0;
        p_list->head = (p_list->head+1)%p_list->size;
        return 0;
    }
    else
    {
        return 1;
    }
    
}

int delete_tail(struct list * p_list){

    if ((p_list->tail-1)%p_list->size != p_list->head)
    {
        p_list->p_buffer[p_list->tail-1] = 0;
        p_list->head = p_list->head+1;
        return 0;
    }
    else
    {
        return 1;
    }
    
}

int print_list(struct list * p_list){

    for (int i=0; i<p_list->size; i++){
        printf("%.2f ", p_list->p_buffer[i]);
    }
    printf("\n");
}




int main(){

    struct list actual_list;

    printf("Inserisci la dimensione della lista: ");
    scanf("%d", &actual_list.size);

    printf("\n size of list: %d \n", actual_list.size);

    init_list(&actual_list);

    print_list(&actual_list);


    for (int i=0; i < actual_list.size; i++){
        printf("Inserisci valore per indice [%d]: \n", i);
        scanf(" %f", &actual_list.p_buffer[i]);

    }

    print_list(&actual_list);
    





}