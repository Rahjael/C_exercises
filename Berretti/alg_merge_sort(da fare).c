#include <stdio.h>

#define VALUES {4.5, 34.234, 1.24, 0.23424, 243.1, 25.8, 12.456} // Valori random a fini di esercitazione

// Function declarations

void merge_sort(float * array, int array_size);
void swap(float * x, float * y);
void divide_and_swap(float * p_array, int start, int end, int size);


//
// Program
//

int main(void)
{
    float values[] = VALUES;
    int size = sizeof(values)/sizeof(values[0]);

    merge_sort(values, size);

    printf("\n\n\n");
    for (int i = 0; i < size; i++)
    {
        printf("%f ", values[i]);
    }

    return 0;
}


//
// Function definitions
//

void swap(float * x, float * y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

void divide_and_swap(float * p_array, int start, int end, int size)
{
    /* Note to myself:

    la ricorsione si occupa della metà sinistra della divisione. Per la metà destra basta scorrere nel seguito,
    quando esce dalla funzione si ritrova alla fine della metà sinistra esterna.

    Probabilmente devo dividere in due l'array corrente, e poi annidarmi in quello di sinistra. Quando torno indietro
    mi ritrovo quello di destra già pronto.

    Preparare variabili per inizio e fine array di sinistra e inizio e fine array di destra.

    Provare questa strada.

    (Continuare a provare con soli indici, senza allocare nuova memoria)

    */

   
    // Creo gli indici per i nuovi array

    int l_start = start;
    int l_end = start+((start+end)/2);
    int l_size = l_end - l_start + 1;

    int r_start = l_end+1;
    int r_end = size-1;
    int r_size = r_end - r_start + 1;


    // LEFT PART

    // recurse until start and end have same value
    if (l_start != l_end)
        divide_and_swap(p_array, l_start, l_end, l_size);


    // if you can't divide, compare and merge

    float * left = &p_array[start];
    float * right = &p_array[end];


    // single comparison
    if (*left > *right)
        swap(left, right);




    // RIGHT PART

    // recurse until start and end have same value
    if (l_start != l_end)
        divide_and_swap(p_array, l_start, l_end, l_size);







}



void merge_sort(float * p_array, int array_size)
{
    // Check immediately for single elemement or empty list
    if (array_size <= 1)
    {
        printf("\nArray is empty, nothing to sort. Exiting function.");
        return;
    }
    // otherwise go through with sorting.

    // setting up needed variables
    int l_start = 0;
    int l_end = (l_start+l_end)/2;
    int l_size =  l_end - l_start + 1;
    int r_start = l_end+1;
    int r_end = array_size-1;
    int r_size =  r_end - r_start + 1;

    // assign first half to recursive function
    divide_and_swap(p_array, l_start, l_end, array_size);

    // assign second half to recursive function
    divide_and_swap(p_array, r_start, r_end, array_size);




}







































/*

    FAILED ATTEMPT

    for (int next_end = blocksize; next_end < array_size; next_end += blocksize, )
    {
        

    }

    do
    {
        // if there are indexes left, assign them
        if (l_index < array_size)
            left = &p_array[l_index];
        
        // if r_index == l_index it means there aren't any slots for the right side
        // so it doesn't assign anything
        if (r_index < array_size && r_index != l_index)
            right = &p_array[r_index];

        // this checks values for swapping, and also checks if there are right sides left
        // if there is no right side, left side is the last number in the array, so no need to swap
        if (*left > *right && l_index < r_index)
            swap(left, right);

        // check indexes. If blocksize is not reached, increment
        if (left+1 < blocksize)    
            left++;
        if (right+1 < blocksize)
            right++;

    } while (left <= blocksize && right <= blocksize);
    
*/
