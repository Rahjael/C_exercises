

struct list {
    float value;
    struct list * next_ptr;
};


void init(struct list **ptrptr)
{
    *ptrptr=NULL;
}

void visit (struct list * ptr)
{
    while (ptr!=NULL)
    {
        ptrinf("%f", ptr->value);
        ptr=ptr->next_ptr;
    }
}

Boolean search (struct list * ptr, float value, struct list ** ptrptr)
/* se esiste un elemento che contiene value, restituisce TRUE
e scrive in *ptrptr il puntatore all'elemento che contiene value.
Altrimenti restituisce FALSE e non modifica *ptrptr */

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
    }

    return found;
}

void pre_insert(struct list ** ptrptr, float value)
/* inserimento in testa */
{
    struct list * tmp_ptr;

    tmp_ptr = *ptrptr;
    *ptrptr = (struct list *)malloc(sizeof(struct list));
    (*ptrptr)->value = value;
    (*ptrptr)->next_ptr = tmp_ptr;
}

Boolean consume_first(struct list ** ptrptr, float * value_ptr)
/* se la lista è vuota restituisce FALSE;
altrimenti restituisce TRUE, scrive in *value_ptr il 
valore nell'elemento in testa e lo cancella dalla lista */

{
    struct list * tmp_ptr;

    if (*ptrptr != NULL){
        *value_ptr=(*ptrptr)->value;
        tmp_ptr = *ptrptr;
        *ptrptr = (*ptrptr)->next_ptr;
        free(tmp_ptr);

        return TRUE;
    }
    else
    {
        return FALSE;
    }
}

void suf_insert(struct list ** ptrptr, float value)
/* inserimento in coda.
scorre il doppio puntatore fino a che questo punta un puntatore nullo,
ovvero il puntatore su cui applicare la malloc
poi applica un inserimento in testa sulla sottolista puntata
dal doppio putnatore */

{
    while (*ptrptr != NULL){
        ptrptr = &((*ptrptr)->next_ptr);
    }

    pre_insert(ptrptr, value);
}


void ord_insert(struct list ** ptrptr, float value)
/* inserimento in ordine.
simile all'inserimento in coda, salvo la condizione
di arresto dell'avanzamento del doppio putnatore */

{
    while(*ptrptr != NULL && (*ptrptr)->value < value){
        ptrptr = &((*ptrptr)->next_ptr);
    }
    pre_insert(ptrptr, value);
    }
}
