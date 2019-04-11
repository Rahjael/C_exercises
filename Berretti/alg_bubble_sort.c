#include <stdio.h>

#define VALUES {4.5, 34.234, 1.24, 0.23424, 243.1, 25.8, 12.456} // Valori random a fini di esercitazione

void bubble_sort(float * array, int array_size);

int main(void)
{
    float values[] = VALUES;
    int size = sizeof(values)/sizeof(values[0]);

    bubble_sort(values, size);

    printf("\n\n\n");
    for (int i = 0; i < size; i++)
    {
        printf("%f ", values[i]);
    }

    return 0;

}

void bubble_sort(float * p_array, int array_size)
{
    int c; // posizione sull'array
    float tmp;
    int swapped;

    do
    {    
        swapped = 0;
        
        for(c = 1; c < array_size; c++)
        {
            if (p_array[c] < p_array[c-1])
            {
                tmp = p_array[c-1];
                p_array[c-1] = p_array[c];
                p_array[c] = tmp;
                swapped = 1;
            }
        }

        printf("\n");
        for (int i = 0; i < array_size; i++)
        {
            printf("%f ", p_array[i]);
        }
    } while (swapped);

}



