#include <stdlib.h>
#include <stdio.h>

/*

Si definisca la funzione c che riceve in ingresso un vettore V di N valori interi
e costruisce una lista istogramma che rappresenta un'unica volta ciascun valore
del vettore assieme al numero delle sue occorrenze nel vettore stesso.

*/


struct histogram_node{
    int value;
    int occurrences;
    struct histogram_node * next;
};


void add_to_histogram(struct histogram_node ** double_pointer, int value, int count)
/* aggiunge un nodo alla lista collegata con puntatori */
{

    struct histogram_node * newnode = (struct histogram_node *)malloc(sizeof(struct histogram_node));

    newnode->value = value;
    newnode->occurrences = count;
    newnode->next = NULL;

    // cerca ultimo elemento
    while(*double_pointer != NULL)
    {
        double_pointer = &((*double_pointer)->next);
    }
    
    *double_pointer = newnode;

}


void build_histogram(struct histogram_node ** head_address, int * V, int N)
{

    int current; // indice per array V originale, elemento esaminato
    int prev; // indice per controllare elementi precedenti
    int next; // indice per contare elementi successivi

    int count; // counter per le occorrenze
    int already_counted; // check per i valori già contati

    for(current = 0; current < N; current++) // per ogni valore in V
    {
        already_counted = 0;

        // questo for controlla se il valore V[current] è già stato contato
        // controllando ogni valore che lo precede
        for(prev = current-1; prev >= 0; prev--)
        {
            if(V[current] == V[prev])
            {
                already_counted = 1;
                break; // basta trovare il primo per smettere di controllare
            }            
        }

        if(!already_counted) // se non è già stato contato, lo conta
        {
            count = 0;

            // conta tutti i next
            for(next = current; next < N; next++)
            {
                if(V[current] == V[next])
                {
                    count++;
                }
            }
            
            // a questo punto aggiungo un nuovo nodo con i dati raccolti

            add_to_histogram(head_address, V[current], count);
        }        
    }
}

void print_histogram(struct histogram_node ** pointer)
{
    while( *pointer != NULL)
    {
        printf("\nValore: %d | %d volte", (*pointer)->value, (*pointer)->occurrences);

        pointer = &((*pointer)->next);

    }
}


void print_test(struct histogram_node ** double_pointer)
{

    printf("\nValore: %d", (((((((*double_pointer)->next)->next)->next)->next)->next)->value) );

}


struct histogram_node * get_last_node(struct histogram_node ** double_pointer)
{
    while( (*double_pointer)->next != NULL)
    {
        double_pointer = &(*double_pointer)->next;
    }

    return (*double_pointer);
}




int main()
{
    struct histogram_node * head;

    int N = 11; // ricevuto da qualche parte
    int V[11] = {4, 3, 6, 4, 2, 5, 1, 2, 3, 2, 5}; // dichiarato da qualche parte

    head = NULL; // head inizializzato

    printf("\nArray: ");
    for(int i = 0; i < N; i++)
    {
        printf("%d ", V[i]);
    }

    printf("\nentro in build");
    build_histogram(&head, V, N);

    printf("\nstampo l'istogramma");
    print_histogram(&head);    

    print_test(&head);


    printf("\nLast node value: %d", (get_last_node(&head))->value );


    return 0;
}