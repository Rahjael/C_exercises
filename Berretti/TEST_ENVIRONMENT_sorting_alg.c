#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MIN 0
#define MAX 1000
#define LENGTH 200


//
//
// COMMON FUNCTIONS
//
//

int get_random_number(int min, int max)
{
    int num;
    num = (rand() % (max - min)) + min;
    return num;
}

void swap_in_place(int * a, int * b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void simple_print_list(int list[], int size)
{
    printf("\n");
    for(int i=0; i<size, i++)
    {
        printf("%d ", list[i]);
    }
}


//
//
// END COMMON FUNCTIONS
//
//

////////////////////////////////////////////////////////////////////////////////////////////

//
//
// ALGORITMI:
//
//


void bubble_sort_berretti(int * num_list, int size)
{
    int found;
    int swap;

    do
    {
        for (int i = 0; i < size - i - 1; i++)
        {
            found = 0;

            if (num_list[i] > num_list[i+1])
            {
                found = 1;
                swap = num_list[i+1];
                num_list[i+1] = num_list[i];
                num_list[i] = swap;
            }
        }

    } while (found != 0);
}


void bubble_sort_adriano(int list[], int size)
{
    int found;

    for (int i = 0; i < size-1; i++)
    {
        found = 0;

        for(int k = 0; k < size-i-1; k++)
        {
            if(list[k] > list[k+1])
            {
                found = 1;
                swap_in_place(&list[k], &list[k+1]);
            }
        }

        if(found == 0)
        {
            break;
        }
    }
}

void bubble_sort_adriano_backforth(int list[], int size) // TODO
{
    int found;

    for (int i = 0; i < size-1; i++)
    {
        found = 0;

        for(int k = 0; k < size-i-1; k++)
        {
            if(list[k] > list[k+1])
            {
                found = 1;
                swap_in_place(&list[k], &list[k+1]);
            }
        }

        if(found == 0)
        {
            break;
        }
    }
}






//
//
// FINE ALGORITMI
//
//





















int main()
{
    // Setta il seed per il generatore random
    srand(time(0));

    // inizializza la lista
    int list[LENGTH];

    // popola l'array di valori random e li stampa
    for (int i = 0; i < LENGTH; i++)
    {
        list[i] = get_random_number(MIN, MAX);
    }

    simple_print_list(&list, LENGTH);

    printf("\nOrdering list...\n");

    //
    //
    // Decommenta l'algoritmo da usare
    //
    //

        //bubble_sort_berretti(list, LENGTH);
        bubble_sort_adriano(list, LENGTH);

    //
    //
    // Fine algoritmi
    //
    //


    // ristampa la lista ordinata
    simple_print_list(&list, LENGTH);

    return 0;
}