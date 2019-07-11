#include <stdio.h>
#include <stdlib.h>



struct node
{
    int value;
    struct node * next;
};


void print_all(struct node * ptr)
{
    while(ptr != NULL)
    {
        printf("%d next: %d", ptr->value, ptr->next);
        ptr = ptr->next;
    }
    printf("\n\n");
}

void add_node_tail(struct node ** ptr, int value)
{
    struct node * newnode;
    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->value = value;
    newnode->next = NULL;

    printf("\nnewnode->value: %d", newnode->value);
    printf("\nnewnode->next: %d\n", newnode->next);

    if((*ptr) == NULL)
    {
        printf("\nInside head == NULL");
        *ptr = newnode; // assegno il nuovo indirizzo di head
    }
    else
    {
        int i = 0; // counter per debug infinite loop
        while(*ptr != NULL && i<5)
        {
            printf("\ninside while");
            ptr = &(*ptr)->next;
            printf("\nptr: %d, ptr->next: %d", ptr, (*ptr)->next);
            i++;
        } // a questo punto ptr dovrebbe puntare all'ultimo elemento

        (*ptr)->next = newnode; // assegno il nuovo indirizzo all'ultimo elemento
    
    }

    printf("\nnode added\n");
}




int main()
{
    struct node * head; // inizializza head
    head = 0;

    add_node_tail(&head, 8);
    add_node_tail(&head, 3);
    add_node_tail(&head, 45);

    printf("print all:");
    print_all(head);



    return 0;
}