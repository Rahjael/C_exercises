#include <stdio.h>

#define VALUES {4.5, 34.234, 1.24, 0.23424, 243.1, 25.8, 12.456} // Valori random a fini di esercitazione

#define VALUES2 {7, 352.34, 5.24, 0.8} // Valori random a fini di esercitazione

// Function declarations

void merge_sort(float * array, int array_size);

void swap(float * x, float * y);



//
// Program
//


int main(void)
{
    float values[] = VALUES;
    float values2[] = VALUES2;

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


void merge_arrays(float * p_array, int array_size, float )
{
    // Check immediately for single elemement or empty list
    if (array_size <= 1)
    {
        printf("\nArray is empty, nothing to sort. Exiting function.");
        return;
    }
    // otherwise go through with sorting.

    // setting up needed variables

    int blocksize = 1;
    int min = 0;
    int max = array_size;
    int l_index = 0;
    int r_index = 1;

    float * left;
    float * right;

    // let's try first with just merging two different arrays


    

























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




}
