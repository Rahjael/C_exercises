/*
    Scrivere la funzione C che riceve in ingresso una lista collegata con puntatori listA
    di valori interi e restituisce tra i parametri formali una lista collegata con puntatori
    listB ottenuta nel modo seguente:

    - Sequenze di elementi consecutivi di listA con stesso valore sono sostituiti dal primo elemento
    della sequenza; gli elementi successivi al primo sono rimossi;

    - Ogni volta che valori ripetuti consecutivi sono trovati è creato un nuovo elemento in listB
    con valore e numero di elementi consecutivi rimossi.

*/

#include <stdio.h>
#include <stdlib.h>

// strutture dati

struct nodeA
{
    int value;
    struct nodeA* next;    
};

struct nodeB
{
    int value;
    int occurrencies;
    struct nodeB * next;
};

// funzioni per testare l'esercizio

void add_to_list(struct nodeA ** headA, int value)
{
    struct nodeA * ptr = *headA; // creo un puntatore temporaneo che mi servirà dopo

    struct nodeA * temp = (struct nodeA *)malloc(sizeof(struct nodeA)); // alloco la memoria per il nuovo nodo
    temp->next = NULL;
    temp->value = value;

    if(*headA == NULL) // se la lista è vuota
    {
        *headA = temp; // assegno a head l'indirizzo del nuovo nodo
    }
    else // se la lista non è vuota scorre fino all'ultimo nodo
    {
        while(ptr->next != NULL) // trovo ultimo nodo della lista
        {
            ptr = ptr->next;
        }

        ptr->next = temp; // aggancio il nuovo nodo
    }
}

void print_listA(struct nodeA * ptr)
/* Stampa lista A */
{
    printf("\nLista A: ");

    while(ptr != NULL)
    {
        printf("%d ", ptr->value);
        ptr = ptr->next;
    }
}

void print_listB(struct nodeB * ptr)
/* Stampa lista B */
{
    printf("\nLista B: ");

    while(ptr != NULL)
    {
        printf("[%d, %d] ", ptr->value, ptr->occurrencies);
        ptr = ptr->next;
    }
}


void recursive_free(struct nodeA * free_from_here)
/* Questa mi serve per liberare la memoria all'interno della funzione */
{
    if(free_from_here->next != NULL) //se è l'ultima chiamata della coda ricorsiva, esce
    {
        recursive_free(free_from_here->next);
        free(free_from_here->next);
        free_from_here->next = NULL;
    }
}

//
// ESERCIZIO:
//

struct nodeB * find_occurrencies(struct nodeA** headA, struct nodeB ** headB)
{
    struct nodeA * currentA = *headA; // puntatore alla lista A
    struct nodeA * scanA; // puntatore per gli elementi successivi a currentA
    struct nodeA * tempA; // temp che mi servirà

    struct nodeB * currentB = *headB; // puntatore a lista B
    struct nodeB * tempB; // temp che mi servirà

    int count; // contatore per le occurrencies

    // scorro currentA su ogni nodo fino alla fine
    while(currentA->next != NULL)
    {        
        if(currentA->value == currentA->next->value ) // trovato valore successivo uguale
        {
            scanA = currentA->next; // imposto il counter            
            count = 2; // resetto il contatore
            
            while(scanA->next != NULL && scanA->next->value == currentA->value) // se il prossimo è uguale, avanzo scan
            {
                count++; // aumento il contatore
                scanA = scanA->next;

            }
            // !!! scanA si trova ora all'ultimo elemento uguale ai precedenti

            // creo il nuovo nodo in listB
            tempB = (struct nodeB *)malloc(sizeof(struct nodeB)); // alloco il nuovo nodo

            // compilo il nuovo nodo
            tempB->next = NULL;
            tempB->value = currentA->value;
            tempB->occurrencies = count;

            // collego il nuovo nodo
            if(currentB == NULL) // la lista è vuota, cambio il puntatore iniziale
            {
                *headB = tempB;
                currentB = *headB;
            }
            else
            {
                // mi assicuro che currentB sia nel posto giusto
                while(currentB->next != NULL)
                {
                    currentB = currentB->next;
                }
                // currentB sta ora puntando all'ultimo nodo di listB, lo collego
                currentB->next = tempB;
            }
            
            // adesso rimuovo gli elementi successivi al primo

            // REMINDER:
            // currentA sta ancora puntando al primo elemento nella serie degli uguali successivi
            // scanA sta ancora puntando all'ultimo elemento degli uguali

            if(scanA->next != NULL) // se la lista non è finita,
            {
                tempA = scanA->next; // salvo l'indirizzo del successivo
                scanA->next = NULL; // setta l'ultimo elemento da liberare
                recursive_free(currentA); // e poi libera la memoria
                currentA->next = tempA; // collego il nodo che ho calcolato al nuovo successivo
            }
            else
            {                   // se la lista è finita
                scanA->next = NULL; // setto l'ultimo elemento da liberare
                recursive_free(currentA); // libera la memoria,
                currentA->next = NULL; // e poi chiudi la lista
            }

            // ho finito di liberare la memoria

        } // fine if(currentA->value == currentA->next->value)

        if(currentA->next != NULL)
        {
            currentA = currentA->next; // avanzo a controllare l'elemento successivo
        }
    }

    return *headB;
}



int main()
{
    struct nodeA * headA = NULL;
    struct nodeB * headB = NULL;

    // popolo e stampo la lista A per l'esercizio
    add_to_list(&headA, 7);
    add_to_list(&headA, 3);
    add_to_list(&headA, 3);
    add_to_list(&headA, 5);
    add_to_list(&headA, 8);
    add_to_list(&headA, 8);
    add_to_list(&headA, 8);
    add_to_list(&headA, 8);
    add_to_list(&headA, 4);
    add_to_list(&headA, 4);
    add_to_list(&headA, 4);
    add_to_list(&headA, 6);
    add_to_list(&headA, 7);
    add_to_list(&headA, 7);
    add_to_list(&headA, 2);
    add_to_list(&headA, 1);
    add_to_list(&headA, 5);
    add_to_list(&headA, 5);
    add_to_list(&headA, 5);
    add_to_list(&headA, 9);
    add_to_list(&headA, 9);
    add_to_list(&headA, 9);
    add_to_list(&headA, 9);

    // stampo listA
    print_listA(headA);

    // opero le modifiche richieste dall'esercizio
    headB = find_occurrencies(&headA, &headB);
    printf("\nModifiche apportate.");

    // ristampo le liste
    print_listA(headA);
    print_listB(headB);

    return 0;
}


