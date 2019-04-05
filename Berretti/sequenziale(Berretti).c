#include <stdio.h>

struct list {
    float * buffer;
    int size;
    int head;
    int tail;
};

void init(struct list * ptr, int size)
/* Alloca il buffer su cui sono memorizzati i valori della lista e
asserisce l'invariante della rappresentazione:
se head==tail la lista è vuota;
altrimenti head è l'indice dell'elemento di testa e
tail è l'indice della prima posizione successiva all'elemento di coda
*/
{
    ptr->buffer=(float *)malloc(size*sizeof(float));
    ptr->size=size;
    ptr->head=0;
    ptr->tail=0;
}


Boolean suf_insert(struct list * ptr, float value)
/* Inserimento in coda: aumenta tail*/
{
    if(((ptr->tail+1)%ptr->size)!=ptr->head)
    {
            ptr->buffer[ptr->tail]=value;
            ptr->tail=(ptr->tail+1)%ptr->size;
            return TRUE;
    }
    else
    {
        return FALSE;
    }
    
}

Boolean pre_insert(struct list * ptr, float value)
/* Inserimento in testa: riduce head */
{
    if (((ptr->tail+1)%ptr->size)!=ptr->head)
    {
        ptr->head=(ptr->head+ptr->size-1)%ptr->size;
        ptr->buffer[ptr->head]=value;
        return TRUE;
    }
    else
    {
        return FALSE;
    }
    
}

void visit(struct list * ptr)
/* visita di stampa */
{
    int position;
    for(position=ptr->head; position != ptr->tail; position=(position+1)%ptr->size){
        printf("%f", ptr->buffer[position]);
    }
}


Boolean search(struct list * ptr, float value)
/* restituisce TRUE se value è contenuto nella lista, FALSE altrimenti */
{
    Boolean found;
    int position;

    position=ptr->head;
    found=FALSE;

    while(found==FALSE && position!=ptr->tail){
        if(ptr->buffer[position]==value)
            found=TRUE;
        else
        {
            position=(position+1)%ptr->size;
        }
        
    }

    return found;
}






int main(){



}