
/*
    Scrivere una lista di valori interi collegata con array e indici

*/

#include <stdlib.h>
#include <stdio.h>


struct record
{
    int value;
    int next;
};

struct list
{
    struct record * buffer;
    int size;
    int first;
    int free;
};


void init(struct list * ptr, int size)
{
    ptr->buffer = (struct record *)malloc(size*sizeof(struct record));
    ptr->size = size;
    ptr->first = size;
    ptr->free = 0;

    for(int i=0; i < size; i++)
        ptr->buffer[i].next = i+1;
}


int tail_insert(struct list * ptr, int value)
{
    int moved;
    int * position_ptr;

    if(ptr->free != ptr->size)
    {
        moved = ptr->free;
        ptr->free = ptr->buffer[moved].next;

        position_ptr = &ptr->first;
        while(*position_ptr != ptr->size)
            position_ptr=&(ptr->buffer[*position_ptr].next);
        
        *position_ptr = moved;
        ptr->buffer[moved].value = value;
        ptr->buffer[moved].next = ptr->size;

    }

}

int head_insert(struct list * ptr, int value)
{
    int moved;

    if(ptr->free != ptr->size)
    {
        moved = ptr->free;
        
        ptr->free = ptr->buffer[moved].next;
        ptr->buffer[moved].next = ptr->first;
        ptr->first = moved;
        ptr->buffer[moved].value = value;

    }


}











int head_insert(struct list * ptr, int value)
{
    if(((ptr->tail+1) & ptr->size) != ptr->head)
    {
        ptr->head = (ptr->head + ptr->size -1) % ptr->size;
        ptr->buffer[ptr->head] = value;

        return 0;
    }
    else
    {
        return 1;
    }
    
}

void visit(struct list * ptr)
{
    int position;
    for (position = ptr->head; position != ptr->tail; position=(++position)%ptr->size)
    {
        printf("%d ", ptr->buffer[position]);
    }
}


int search(struct list * ptr, int value)
{
    int position;

    position = ptr->head;
    int found = 0;

    while(!found && position < ptr->tail)
    {
        if(ptr->buffer[position]==value)
        {
            found = 1;
        }
        else
        {
            position = (++position)%ptr->size;
        }
        
    }
    
    return found;
}







int main()
{
    


    return 0;
}