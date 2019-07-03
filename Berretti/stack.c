
/*

    Scrivi uno programma con uno stack con le seguenti funzioni:

        l'utente può aggiungere o eliminare un intero
        viene stampata la lista ad ogni operazione
        'e' per uscire


 */


#include <stdio.h>
#include <stdlib.h>


struct stack
{
    int * buffer;
    int TOS;
    int size;
};


void initialise_stack(struct stack * stack)
{
    stack->buffer = (int *)malloc((stack->size)*sizeof(int));
    stack->TOS = -1;
    printf("\nStack inizializzato.");
}

void push(struct stack * stack, int num)
{
    (stack->TOS)++;
    stack->buffer[stack->TOS] = num;
}

void pop(struct stack * stack)
{
    (stack->TOS)--;
}

void show_stack(struct stack * stack)
{
    int i;
    printf("\n");
    for(i = 0; i <= stack->TOS; i++)
    {
        printf("%d ", stack->buffer[i]);
    }
}


void main()
{
    struct stack stack;
    int choice;

    printf("Inserisci la dimensione dello stack:");
    scanf("%d", &stack.size);
    printf("\nStack size: %d", stack.size);

    initialise_stack(&stack);

    do
    {
        if(stack.TOS+1 >= stack.size)
        {
            printf("\nStack pieno. Esco dal programma.");
            break;
        }


        printf("\nInserisci un numero per aggiungerlo, 'c' per cancellare l'ultimo: ");
        scanf("%d", &choice);

        if(choice != 0)
        {
            push(&stack, choice);
            printf("\n%d aggiunto allo stack.");
            show_stack(&stack);
        }
        else
        {
            pop(&stack);
            printf("\nStack popped.");
            show_stack(&stack);
        }


    } while (1);
    
// Fine programma
}