

struct record {
    float value;
    int next;
};

struct list {
    int first;
    int free;
    int size;
    struct record * buffer;
};

void init(struct list * ptr, int size)
/* alloca il buffer e asserisce l'invariante della lista:
first ha il valore illegale che indica che non ci sono elementi memorizzati;
free indirizza il primo record;
tutti i record sono concatenati a partire dal primo
per averli disponibili come record liberi.
*/

{
    int count;

    ptr->buffer=(struct record *)malloc(size*sizeof(struct record));
    ptr->size = size;
    ptr->first = ptr->size;
    ptr->free = 0;

    for (count=0; count < ptr->size; count++){
        ptr->buffer[count].next=count+1;
    }
}



void visit(struct list * ptr)
{
    int position;

    position = ptr->first;

    while(position!=ptr->size)
    {
        printf("%f", ptr->buffer[position].value);
        position=ptr->buffer[position].next;
    }
}


Boolean search (struct list * ptr, float value)
{
    int position;
    Boolean found;

    position=ptr->first;
    found=FALSE;

    while (found == FALSE && position != ptr->size)
    {
        if(ptr->buffer[position].value==value){
            found=TRUE;
        }
        else
        {
            position =ptr->buffer[position].next;
        }
    }
    return found;        
}


Boolean pre_insert(struct list * ptr, float value)
/* se la lista libera non è vuota ne sgancia il primo elemento,
lo aggancia in testa alla lista dei valori
e ci memorizza il valore da inserire */

{
    int moved;

    if(ptr->free != ptr->size)
    {
        moved = ptr->free;

        ptr->free=(ptr->buffer[ptr->free]).next;

        ptr->buffer[moved].value=value;
        ptr->buffer[moved].next=ptr->first;
        ptr->first=moved;

        return TRUE;
    }
    else
    {
        return FALSE;
    }
    
}



Boolean suf_insert(struct list * ptr, float value)
/* se la lista libera non è vuota ne sgancia il primo elemento
el lo aggancia in coda alla lista dei valori,
ci copia sopra il valore da inserire
e attribuisce il valore illegale al successore.
altrimenti restituisce FALSE. */

{
    int moved;
    int * position_ptr;

    if(ptr->free!=ptr->size)
    {
        moved=ptr->free;
        ptr->free=((ptr->buffer)[ptr->free]).next;

        position_ptr=&ptr->first;

        while(*position_ptr!=ptr->size)
            position_ptr=&(ptr->buffer[*position_ptr].next);
        
        *position_ptr=moved;
        ptr->buffer[moved].value=value;
        ptr->buffer[moved].next=ptr->size;

        return TRUE;
    }
    else
    {
        return FALSE;
    }
}


Boolean ord_insert(struct list * ptr, float value)
/* assume che la lista sia ordinata,
inserisce il nuovo elemento in ordine
è analoga alla funzione di inserimento in coda salvo
l'aggiunta di una seconda condizione sul while
e uno swap nell'inserimento finale */

{
    int moved;
    int * position_ptr;

    if(ptr->free!=ptr->size)
    {
        moved=ptr->free;
        ptr->free=((ptr->buffer)[ptr->free]).next;

        position_ptr=&ptr->first;

        while(*position_ptr!=ptr->size &&
                ptr->buffer[*position_ptr].value<value)
            position_ptr=&(ptr->buffer[*position_ptr].next);

            ptr->buffer[moved].value=value;
            ptr->buffer[moved].next=*position_ptr;
            *position_ptr=moved;
            
            return TRUE;
    }
    else
    {
        return FALSE;
    }
    
}