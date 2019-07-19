#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MIN 0
#define MAX 10
#define LENGTH 30


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



void bubble_sort(int * array, int size)
{
    int found = 1;
    int temp;
    int end = 0;

    while(found == 1)
    {
        found = 0;

        for(int i = 0; i < size-end-1; i++)
        {
            if(array[i] > array[i+1])
            {
                found = 1;
                temp = array[i];
                array[i] = array[i+1];
                array[i+1] = temp;                
            }
        }
        end++;
    }
}



void bubble_sort_improved(int list[], int size)
{
    int temp;
    int i;
    int start = 0;
    int end = size-1;

    int found = 1;
    
    while(found == 1)
    {
        found = 0;
        i = start;

        while(i < end)
        {
            if(list[i] > list[i+1])
            {
                found = 1;
                temp = list[i];
                list[i] = list[i+1];
                list[i+1] = temp;                
            }

            i++;
        }

        end--;
        i = end;

        while(i >= start)
        {
            if(list[i] > list[i+1])
            {
                found = 1;
                temp = list[i];
                list[i] = list[i+1];
                list[i+1] = temp;                
            }
            i--;
        }

        start++;
    }
}


void selection_sort(int * array, int size)
{
    int * min;
    int temp;

    for(int i=0; i < size; i++)
    {
        min = &array[i];

        for(int k = i+1; k < size; k++)
        {
            if(array[k] < *min)
            {
                min = &array[k];
            }
        }

        temp = array[i];
        array[i] = *min;
        *min = temp;        

    }
}


void insertion_sort(int * array, int size)
{
    int temp;
    
    for(int i=1; i < size; i++)
    {
        for(int k = i; k >= 1; k--)
        {
            if(array[k] < array[k-1])
            {
                temp = array[k];
                array[k] = array[k-1];
                array[k-1] = temp;
            }
            else
            {
                break;
            }            
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

        // i divide ricevono SEMPRE l'indirizzo dove inizia la prima partizione di main array e di temp, 
        // la dimensione dell'array, l'indirizzo dove inizia la seconda partizione di main array e di temp

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



// INIZIO QUICKSORT

void quicksort(int * array, int start, int end)
{
    simple_print_list(array, 8);

    if(start < end)
    {
        int pivot = end;
        int left = start;
        int right = end;
        int temp;

        while(left < right)
        {
            while(array[left] <= array[pivot] && left < right)
            {
                ++left;
            }

            while (array[right] >= array[pivot] && right > left)
            {
                --right;
            }

            temp = array[right];
            array[right] = array[left];
            array[left] = temp;

        }

        temp = array[right];
        array[right] = array[pivot];
        array[pivot] = temp;

        quicksort(array, start, (right-1));
        quicksort(array, right, end);

    }    
}

// FINE QUICKSORT




//
//
// FINE ALGORITMI
//
//


// ALGORITMI MIEI

void double_bubblesort(int * array, int size)
{
    int temp;
    int inner;
    int outer;
    

    int innerfound = 1;
    int outerfound = 1;

    while(innerfound == 1)
    {
        innerfound = 0;
        
        if(outerfound == 1)
        {
            printf("\ninizio outer");
            
            outer = 0;
            
            while(outer < (size/2))
            {
                printf("\nouter check");
                if(array[outer] > array[(size-1)-outer])
                {
                    temp = array[outer];
                    array[outer] = array[(size-1)-outer];
                    array[(size-1)-outer] = temp;

                    outerfound = 1;
                }
                
                outer++;

            }

            simple_print_list(array, size);
        }

    
        printf("\ninizio inner");

        inner = 0;

        printf("\ninner loop");
        while(inner < size-1)
        {
            printf("\ninner check");
            if(array[inner] > array[inner+1])
            {
                temp = array[inner];
                array[inner] = array[inner+1];
                array[inner+1] = temp;

                innerfound = 1;
            }

            inner++;
        }
            simple_print_list(array, size);
    }
}







// FINE ALGORITMI MIEI



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

        //bubble_sort(list, LENGTH);

        //bubble_sort_improved(list, LENGTH);

        //selection_sort(list, LENGTH);

        //insertion_sort(list, LENGTH);

        //mergesort_main(list, LENGTH);

        //quicksort(list, 0, LENGTH-1);

        double_bubblesort(list, LENGTH);

    //
    //
    // Fine algoritmi
    //
    //


    // ristampa la lista ordinata
    simple_print_list(list, LENGTH);

    return 0;
}