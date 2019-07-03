

/*

Implement a List linked by pointers with the following operations:
○ Init empty list
○ tail/head insert
○ visit (print all values)
○ insert at specific position
○ ordered insert
○ search value and return the address

*/


#include <stdio.h>
#include <stdlib.h>


typedef struct linked_item
{
    float value;
    struct ListItem * next;
}linked_item;


void init_list(linked_item ** list_head)
{
    *list_head = NULL;
}

void head_insert(linked_item * list_head, float value)
/*
    Non capisco il bisogno del doppio puntatore, così dovrebbe funzionare lo stesso
*/
{
    // creo il nuovo elemento da linkare
    linked_item * new_item;
    new_item = (linked_item *)malloc(sizeof(linked_item));

    // aggancio il next del nuovo elemento al secondo elemento
    new_item->next = list_head->next;
    // imposto il valore del nuovo elemento
    new_item->value = value;
    // risetto la testa per puntare al nuovo elemento
    list_head->next = &new_item;
}

void tail_insert()




int main()
{
    linked_item * list_head;

    init_list(&list_head);




    return 0;
}