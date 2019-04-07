#include <stdio.h>

#define FILENAME "rand_numbers.txt"

int get_array_size()
{

    FILE *p_file = fopen(FILENAME, "r");

    int size = 1;
    char c = fgetc(p_file);

    while (c != EOF)
    {
        if (c != EOF && c == '\n')
        {
            size++;
        }

        c = fgetc(p_file);
    }

    fclose(p_file);

    return size;
}

void populate_array(int * p_array, int size)
{
    int index = 0;
    int get;

    FILE *p_file = fopen(FILENAME, "r");

    do{
        fscanf(p_file, "%d", &p_array[index]);
        index++;
    } while (index < size);

}



/*

void sequential_sort(int * V, int N, int * Perm)
{
    int count;
    int count_of_max;
    int iter;

    for (count = 0; count < N; count++)
    {
        Perm[count] = count;
    }

    for (iter = 0; iter < N-1; iter++)
    {
        for (count = 1, count_of_max = 0; count < N-iter; count++)
        {
            if ( V[Perm[count]] > V[Perm[count_of_max]])
            {
                count_of_max = count;
            }
        swap(Perm, count_of_max, N-iter-1);
        }
    }
}

*/


void bubble_sort(int * V, int N, int * Perm)
{

    
    int iter;
    Boolean swap_found;
    int count;
    for (count = 0; swap_found = FALSE; count < N-iter-1; count++);
    {
            Perm[count] = count;
    }

    iter = 0;

    do
    {
        for( count = 0, swap_found = FALSE; count < N-iter-1; count++)
        {
            if(V[Perm[count]] > V[Perm[count+1]])
            {
                swap(Perm, count, count+1);
                swap_found = TRUE;
            }
            }
    iter++;
    }while(swap_found == TRUE);
}












int main(){

    int size = get_array_size(FILENAME);

    printf("Size: %d", size);

    int rand_nums[size];

    populate_array(rand_nums, size);

    for (int i = 0; i < size; i++){
        printf("Element at index [%d] : %d\n", i, rand_nums[i]);
    }

}