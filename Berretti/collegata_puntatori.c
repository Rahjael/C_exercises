#include <stdio.h>
#include <stdlib.h>


typedef int Boolean;
#define TRUE 1
#define FALSE 0


struct record
{
    int value;
    struct list * next;
};


void init(struct record ** ptrptr)
{
    *ptrptr = NULL;
}

void print_list(struct record * ptr)
{
    while(ptr != NULL)
    {
        printf("%d ", ptr->value);
        ptr = ptr->next;
    }
}


Boolean search (struct list * ptr, int value, struct list ** ptrptr)
{
    Boolean found;

    found = FALSE;

    while(ptr != NULL && found == FALSE)
    {
        if(ptr->value == value)
        {
            found = TRUE;
            *ptrptr = ptr;
        }
        else
        {
            ptr = ptr->next_ptr;
        }

    return found;

    }
}



void pre_insert(struct list ** ptrptr, int value)
{
    struct list * tmp_ptr;

    tmp_ptr = *ptrptr;
    *ptrptr = (struct list *)malloc(sizeof(struct list));
    (*ptrptr)->value = value;
    (*ptrptr)->next_ptr= tmp_ptr;
}

