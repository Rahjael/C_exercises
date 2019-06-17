
/*
    Scrivere una lista di valori interi collegata con array e indici

*/


struct list
{
    int * buffer;
    int size;
    int head;
    int tail;
};


void init(struct list * ptr, int size)
{
    ptr->buffer = (int *)malloc(size*sizeof(int));
    ptr->size = size;
    ptr->head = 0;
    ptr->tail = 0;
}

int tail_insert(struct list * ptr, int value)
{
    if(((ptr->tail+1) % ptr->size) != ptr->head)
    {
        ptr->buffer[ptr->tail] = value;
        ptr->tail = (++(ptr->tail) % (ptr->size));

        return 0;
    }
    else
    {
        return 1;
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