#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MIN 0
#define MAX 100
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

void simple_print_list(int * list, int size)
{
    printf("\n");
    for(int i=0; i < size; i++)
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

// INIZIO MERGESORT

void mergesort_impera(int * main, int size, int * temp)
{
    // creo gli indici per gli array
    int l_index = 0; // fino a (size/2)-1
    int r_index = (size/2); // fino a size-1
    int main_index = 0;
    
    for(int i = 0; i < size; i++) // copio main in temp
    {
        temp[i] = main[i];
    }

    while(l_index < (size/2) && r_index < size) // finché entrambi i subarray hanno valori
    {
        if(temp[l_index] < temp[r_index])
        {
            main[main_index] = temp[l_index];
            l_index++;
        }
        else
        {
            main[main_index] = temp[r_index];
            r_index++;
        }

        main_index++;
    }

    // se esiste solo il subarray di sinistra
    while(l_index < (size/2))
    {
        main[main_index] = temp[l_index];
        l_index++;
        main_index++;
    }

    //se esiste solo il subarray di destra
    while(r_index < size)
    {
        main[main_index] = temp[r_index];
        r_index++;
        main_index++;
    }

}

void mergesort_divide(int * main_array, int size, int * temp)
{
    if(size > 1) // divide fino a che size > 1
    {
        mergesort_divide(main_array, (size/2), temp);
        mergesort_divide(&main_array[size/2], size-(size/2), &temp[size/2]);
        mergesort_impera(main_array, size, temp);
    }
}


void mergesort_main(int * main_array, int size)
/*  
    Funzione che contiene il resto dell'algoritmo
    Creo un solo array temp e lo passo tra le funzioni, 
    in questo modo evito di richiamare malloc() e free() ogni volta che splitto l'array.
    In pratica il processo di divisione viene solo virtualizzato e lo swap avviene in place sull'array temp
*/
{
    int * temp;
    temp = (int *)malloc(sizeof(int)*size); // creo l'array di appoggio

    mergesort_divide(main_array, size, temp); // chiamo il divide ricorsivo: in pratica tutto l'algoritmo si svolge qui dentro

    free(temp); // libero l'array di appoggio ed esco dalla funzione
}
// FINE MERGESORT


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

    printf("\n\nRandom numbers:\n");
    simple_print_list(list, LENGTH);

    printf("\n\nOrdering list...\n");

    //
    //
    // Decommenta l'algoritmo da usare
    //
    //

        //bubble_sort_berretti(list, LENGTH);
        //bubble_sort_adriano(list, LENGTH);

        mergesort_main(list, LENGTH);

    //
    //
    // Fine algoritmi
    //
    //


    // ristampa la lista ordinata
    simple_print_list(list, LENGTH);

    return 0;
}