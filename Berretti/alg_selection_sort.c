#include <stdio.h>

#define VALUES {4.5, 34.234, 1.24, 0.23424, 243.1, 25.8, 12.456} // Valori random a fini di esercitazione

void selection_sort(float * array, int array_size);

int main(void)
{
    float values[] = VALUES;
    int size = sizeof(values)/sizeof(values[0]);



    selection_sort(values, size);

    printf("\n\n\n");
    for (int i = 0; i < size; i++)
    {
        
        printf("%f ", values[i]);
    }

    return 0;

}

void selection_sort(float * p_array, int array_size)
{
    float temp; // Appoggio
    int c; // Current index
    int s; // Swap index
    
    float * p_minimum;

    for (c = 0; c < array_size; c++)
    {
        temp = p_array[c];
        p_minimum = &p_array[c];

        for(s = c+1; s < array_size; s++)
        {
            if (p_array[s] < *p_minimum)
                p_minimum = &p_array[s];
        }

        printf("\nswappo");

        // swap if necessary
        if (*p_minimum < temp)
        {
            p_array[c] = *p_minimum;
            *p_minimum = temp;
        }

        printf("\n");
        for (int i = 0; i < array_size; i++)
        {
            printf("%f ", p_array[i]);
        }



    }

}
