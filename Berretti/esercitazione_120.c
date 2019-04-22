#include <stdio.h>
#include <stdlib.h>

/*
    Esercizio 3 compito 8 gennaio




*/







int main(void){











    return 0;
}


Boolean deleteAndInvert(struct list **ptrA, float target){

    struct list * tmp, ** headA, ** V;
    int count = 0, N;
    headA = ptrA;
    while(*ptrA!=NULL)
    {
        if (isequal(*ptrA)->value, target)
        {
            tmp = *ptrA;
            *ptrA = (*ptrA)->next.ptr;
            free(tmp);
        }
        else
        {
            ptrA = &((*ptrA)->next.ptr);
            count++;
        }
        
    }

    V = (struct list **)malloc(sizeof(struct list *)*count);
    ptrA = headA;
    N = count;
    count = 0;

    while (*ptrA != NULL)
    {
        V[count] = *ptrA;
        ptrA = &((*ptrA)->next.ptr);
        count++;
    }

    for (count = N-1; count >= 0; count--)
    {
        *ptrA = V[count];
        ptrA = &((*ptrA)->next.ptr);
    }
    *ptrA = NULL;

    return success;

}