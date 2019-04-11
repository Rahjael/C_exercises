#include <stdio.h>

#define VALUES {4.5, 34.234, 1.24, 0.23424, 243.1, 25.8, 12.456} // Valori random a fini di esercitazione

void insertion_sort(float * array, int array_size);

int main(void)
{
    float values[] = VALUES;
    int size = sizeof(values)/sizeof(values[0]);

    insertion_sort(values, size);

    printf("\n\n\n");
    for (int i = 0; i < size; i++)
    {
        printf("%f ", values[i]);
    }

    return 0;

}

void insertion_sort(float * p_array, int array_size)
{
    float temp; // Appoggio
    int c; // Current index
    int s; // Swap index

    for (c = 1; c <array_size; c++)
    {
        temp = p_array[c];
        s = c-1;

        while(s >= 0 && p_array[s] > temp)
        {
            p_array[s+1] = p_array[s];
            s--;
        }

        p_array[s+1] = temp;

    }
}
