#include <stdio.h>
#include <stdlib.h>

struct node
{
    int value;
    struct node * next;
};

void print_all(struct node * ptr)
{
    int i = 0;
    while(ptr != NULL && i<20)
    {
        printf("%d ", ptr->value);
        ptr = ptr->next;
        i++;
    }
}

void append(struct node ** ptr, int value)
{
    struct node * newnode;
    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->value = value;
    newnode->next = NULL;

    if((*ptr) == NULL)
    {
        *ptr = newnode; // assegno il nuovo indirizzo di head
    }
    else
    {
        struct node * find_last = *ptr;
        
        while(find_last->next != NULL)
        {
            find_last = find_last->next;
        } // a questo punto ptr dovrebbe puntare all'ultimo node

        find_last->next = newnode; // assegno il nuovo indirizzo all'ultimo elemento 
        
        printf("\nho aggiunto %d", value);   
    }
}

void add_front(struct node ** head, int value)
{
    struct node * newnode;
    newnode = (struct node *)malloc(sizeof(struct node)); // alloca memoria per nuovo nodo

    newnode->value = value; // assegno il valore al nuovo nodo

    if(*head != NULL) // se la lista non è vuota
    {
        newnode->next = *head; // il nuovo nodo punta al secondo
    }
    else
    {
        newnode->next = NULL; // se a lista era vuota il nuovo nodo punta a NULL
    }
    
    *head = newnode;
}

void delete(struct node ** ptr, int value)
{
    struct node * temp = *ptr; // creo un puntatore di appoggio che mi servirà in ogni caso

    if((*ptr)->value == value) // l'elemento è il primo della lista?
    {
        *ptr = (*ptr)->next; // riassegno head
        free(temp); // libero l'elemento da cancellare
    }
    else // altrimenti è un valore successivo
    {
        while((temp->next)->value != value) // cerca il valore da eliminare rimanendo sempre un node indietro
        {
            temp = temp->next;
        }
        // sto puntando al node precedente al valore da eliminare.
        // salvo l'indirizzo del valore da eliminare
        struct node * to_delete = temp->next;

        // assegno l'indirizzo del valore successivo
        temp->next = (temp->next)->next;

        free(to_delete);; // libero l'elemento da eliminare        
    }
}

int main()
{
    struct node * head; // inizializza head
    head = NULL;

    append(&head, 3);
    append(&head, 8);
    append(&head, 45);
    append(&head, 4);
    append(&head, 63);
    append(&head, 68);
    append(&head, 45);
    append(&head, 4);

    add_front(&head, 99);


    printf("\n\nprint all: ");
    print_all(head);

    delete(&head, 99);

    printf("\n\nprint all: ");
    print_all(head);

    delete(&head, 63);
    
    printf("\n\nprint all: ");
    print_all(head);


    delete(&head, 3);
    delete(&head, 65);

    printf("\n\nprint all: ");
    print_all(head);

    return 0;
}