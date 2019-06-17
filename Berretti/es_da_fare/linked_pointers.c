
//#include <stdlib.h>
#include <stdio.h>


typedef unsigned short int Boolean;

#define TRUE 1
#define FALSE 0

struct list
{
    float value;
    struct list * next_ptr;
};

void init(struct list ** ptrptr)
{
    *ptrptr = NULL;
}

void visit(struct list * ptr)
{
    while(ptr != NULL)
    {
        ptr=ptr->next_ptr;
    }
}

Boolean search(struct list * ptr, float value, struct list ** ptrptr)
{
    Boolean found;

    found = FALSE;
    while (ptr != NULL && found == FALSE)
    {
        if(ptr->value==value)
        {
            found = TRUE;
            *ptrptr=ptr;
        }
        else
        {
            ptr=ptr->next_ptr;
        }
        return found;
    }
}


void pre_insert(struct list ** ptrptr, float value)
{
    struct list * tmp_ptr;

    tmp_ptr= *ptrptr;
    *ptrptr=(struct list *)malloc(sizeof(struct list));
    (*ptrptr)->value=value;
    (*ptrptr)->next_ptr=tmp_ptr;
}

Boolean consume_first(struct list ** ptrptr, float * value_ptr)
{
    struct list * tmp_ptr;

    if(*ptrptr!=NULL)
    {
        *value_ptr=(*ptrptr)->value;
        tmp_ptr= *ptrptr;
        *ptrptr=(*ptrptr)->next_ptr;
        free(tmp_ptr);
        return TRUE;
    }
    else
    {
        return FALSE;
    }
    
}


void suf_insert(struct list ** ptrptr, float value)
{
    while(*ptrptr!=NULL)
    {
        ptrptr=&((*ptrptr)->next_ptr);
    }
    pre_insert(ptrptr, value);
}


void ord_insert(struct list ** ptrptr, float value)
{
    while(*ptrptr != NULL && (*ptrptr)->value < value)
        ptrptr = &((*ptrptr)->next_ptr);
    pre_insert(ptrptr,value);
}




int main()
{
    struct list ** superpointer;


}