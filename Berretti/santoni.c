
// Esercizio Esame

#include <stdlib.h>
#include <stdio.h>

typedef unsigned short int Bool;
#define TRUE 1
#define FALSE 0


//Reference List
struct list_a{
    int value;
    struct list_a * next_ptr;
};

//Repeated values List
struct list_b{
    int value;
    int repeated;
    struct list_b * next_ptr;
};

//Prototype
void init_a(struct list_a ** ptrptr);
void init_b(struct list_b ** ptrptr);
Bool pre_insert_a(struct list_a ** ptrptr, int value);
Bool suf_insert_a(struct list_a ** ptrptr, int value);
Bool pre_insert_b(struct list_b ** ptrptr, int value, int repeated);
Bool suf_insert_b(struct list_b ** ptrptr, int value, int repeated);
Bool ord_insert_a(struct list_a ** ptrptr, int value);
Bool pre_remove_a(struct list_a ** ptrptr); //check
Bool suf_remove_a(struct list_a ** ptrptr);
Bool ord_remove_a(struct list_a ** ptrptr, int target);
void visit_a(struct list_a *ptr);
void visit_b(struct list_b *ptr);
Bool search_a(struct list_a * ptr, int target);
Bool search_b(struct list_b * ptr, int target);
struct list_b * esercizio_5(struct list_a ** ptrptr_a, struct list_b ** ptrptr_b);

//Main
int main()
{
    struct list_a * ptr_a;
    struct list_b * ptr_b;


    // Initialization
    init_a(&ptr_a);
    init_b(&ptr_b);
    // Pre_Insert
    pre_insert_a(&ptr_a, 5);
    pre_insert_a(&ptr_a, 3);
    pre_insert_a(&ptr_a, 3);
    pre_insert_a(&ptr_a, 3);
    pre_insert_a(&ptr_a, 4);
    pre_insert_a(&ptr_a, 1);
    pre_insert_a(&ptr_a, 5);
    pre_insert_a(&ptr_a, 5);
    pre_insert_a(&ptr_a, 1);
    pre_insert_a(&ptr_a, 1);
    pre_insert_a(&ptr_a, 3);
    pre_insert_a(&ptr_a, 3);

    printf("\nstampo lista A");
    visit_a(ptr_a);

    printf("\nesercizio");
    esercizio_5(&(ptr_a), &(ptr_b));

    visit_a(ptr_a);

    visit_b(ptr_b);
/*
    // Suf_Insert
    suf_insert_a(&ptr_a, 7);
    suf_insert_a(&ptr_a, 8);
    suf_insert_a(&ptr_a, 9);

    visit_a(ptr_a);

    // Ord_Insert
    ord_insert_a(&ptr_a, 2);
    ord_insert_a(&ptr_a, 4);
    ord_insert_a(&ptr_a, 6);

    visit_a(ptr_a);

    // Remove
    pre_remove_a(&ptr_a, &value);
    printf("\nValue %d has been removed from the list",value);
    suf_remove_a(&ptr_a, &value);
    printf("\nValue %d has been removed from the list",value);
    ord_remove_a(&ptr_a,3);
    ord_remove_a(&ptr_a,7);

    visit_a(ptr_a);
    visit_b(ptr_b);
    // Search
    if ( search_a(ptr_a,10) )
        printf("\nSearch termined with success!");
    else
        printf("\nSearch termined without success!");

    printf("\n");
*/
    return 0;
}


void init_a(struct list_a ** ptrptr)
{
    *ptrptr = NULL;
}

void init_b(struct list_b ** ptrptr)
{
    *ptrptr = NULL;
}

Bool pre_insert_a(struct list_a **ptrptr, int value)
{
    struct list_a * tmp_ptr;
    tmp_ptr = (struct list_a *)malloc(sizeof(struct list_a));
    if ( tmp_ptr != NULL ) {
        tmp_ptr->value = value;
        tmp_ptr->next_ptr = *ptrptr;
        *ptrptr = tmp_ptr;
        return TRUE;
    }
    else
        return FALSE;

}

Bool pre_insert_b(struct list_b **ptrptr, int value, int repeated)
{
    struct list_b * tmp_ptr;
    tmp_ptr = (struct list_b *)malloc(sizeof(struct list_b));
    if ( tmp_ptr != NULL ) {
        tmp_ptr->value = value;
        tmp_ptr->next_ptr = *ptrptr;
        tmp_ptr->repeated= repeated;
        *ptrptr = tmp_ptr;
        return TRUE;
    }
    else
        return FALSE;

}

Bool suf_insert_a(struct list_a **ptrptr, int value)
{
    while( *ptrptr != NULL )
        ptrptr = &((*ptrptr)->next_ptr);
    if ( pre_insert_a(ptrptr,value) )
        return TRUE;
    else
        return FALSE;
}

Bool suf_insert_b(struct list_b **ptrptr, int value, int repeated)
{
    while( *ptrptr != NULL )
        ptrptr = &((*ptrptr)->next_ptr);
    if ( pre_insert_b(ptrptr, value, repeated) )
        return TRUE;
    else
        return FALSE;
}
/*
Bool ord_insert_a(struct list_a **ptrptr, int value)
{
    while( *ptrptr != NULL && (*ptrptr)->value < value )
        ptrptr = &((*ptrptr)->next_ptr);
    if ( pre_insert_a(ptrptr,value) )
        return TRUE;
    else
        return FALSE;
}

Bool pre_remove_a(struct list_a **ptrptr)
{
    struct list_a * tmp_ptr;
    int value;
    if ( *ptrptr != NULL ) {
        tmp_ptr = *ptrptr;
        value = tmp_ptr->value;
        *ptrptr = (*ptrptr)->next_ptr;
        free(tmp_ptr);
        return TRUE;
    }
    else
        return FALSE;
}


Bool suf_remove_a(struct list_a ** ptrptr, int * p_value)
{
    if ( *ptrptr != NULL ) {
        while( (*ptrptr)->next_ptr != NULL ) {
            ptrptr = &((*ptrptr)->next_ptr);
        }
        pre_remove_a(ptrptr,&p_value);
        return TRUE;
    }
    else
        return FALSE;
}

Bool ord_remove_a(struct list_a ** ptrptr, int target)
{
    int value;
    Bool found = FALSE;

    if ( *ptrptr != NULL ) {
        while( *ptrptr != NULL && found == FALSE ) {
            if ((*ptrptr)->value == target) {
                pre_remove_a(ptrptr, &value);
                printf("\nValue %d has been removed from the list",value);
                found = TRUE;
            }
            else
                ptrptr = &((*ptrptr)->next_ptr);
        }
    }
    return found;
}
*/
void visit_a(struct list_a * ptr)
{
    printf("\nList: ");
    while ( ptr != NULL ) {
        printf("%d ", ptr->value);
        ptr = ptr->next_ptr;
    }
}

void visit_b(struct list_b * ptr)
{
    printf("\nList: (value) [repeated] ");
    while ( ptr != NULL ) {
        printf("(%d) [%d] ", ptr->value, ptr->repeated);
        ptr = ptr->next_ptr;
    }
}

Bool search_a(struct list_a * ptr, int target)
{
    Bool found = FALSE;

    while( ptr != NULL && found == FALSE ) {
        if ( ptr->value == target )
            found = TRUE;
        else
            ptr = ptr->next_ptr;
    }
    return found;
}
/*
Bool search_b(struct list_b * ptr, int target)
{
    Bool found = FALSE;

    while( ptr != NULL && found == FALSE ) {
        if ( ptr->value == target )
            found = TRUE;
        else
            ptr = ptr->next_ptr;
    }
    return found;
}
*/






struct list_b * esercizio_5(struct list_a ** ptrptr_a, struct list_b ** ptrptr_b)
{
    int count=1;
    // count deve essere 1 altrimenti te ne conta uno in meno




    int old = ((*ptrptr_a)->value)-1; //Avoid random match
    int new = ((*ptrptr_a)->value);
    Bool is_same=FALSE;

    while(*ptrptr_a != NULL)
    {
        if((*ptrptr_a)->value != old)
        {
            if(count!=1)
            // solito discorso qua




            {
                suf_insert_b(ptrptr_b,old,count);
                count=1;
                // e qua



            }

            old=new;

            if((*ptrptr_a)!=NULL)
            {



                // qui ho aggiunto il controllo sul successivo puntatore, se sei all'ultimo elemento
                // della lista non deve andare al successivo
                if( (*ptrptr_a)->next_ptr != NULL)
                {
                    ptrptr_a= &(*ptrptr_a)->next_ptr;
                    new=(*ptrptr_a)->value;
                }
                else
                    *ptrptr_a = NULL;
                    // e qui lo imposti a NULL se è l'ultimo elemento della lista
                    // altrimenti il while principale ti va in loop


            }
        }
        else
        {
            count++;
            old=new;

            // solito discorso come sopra
            if( (*ptrptr_a)->next_ptr != NULL)
            {
                ptrptr_a = &(*ptrptr_a)->next_ptr;
                new=(*ptrptr_a)->value;
            }
            else
                *ptrptr_a = NULL;
        }
    }

    return NULL;
}




