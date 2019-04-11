
/*

    Scrivere la funzione C che riceve in ingresso una lista sequenziale 
    di valori float e la ordina con l’algoritmo di selezione

*/

#include <stdio.h>

#define VALUES {4.5, 34.234, 1.24, 0.23424, 243.1, 25.8, 12.456} // Valori random a fini di esercitazione

void seq_sort(float * array, int array_size);

int main(void)
{
    float values[] = VALUES;
    int size = sizeof(values)/sizeof(values[0]);

    seq_sort(values, size);

    printf("\n\n\n");
    for (int i = 0; i < size; i++)
    {
        printf("%f ", values[i]);
    }

    return 0;

}

void seq_sort(float * array, int array_size)
{
    float temp; // variabile di appoggio
    float * min_value; // Puntatore per il valore minimo

    for (int i = 0; i < array_size; i++) // Cicla su tutto l'array
    {
        min_value = &array[i]; // Imposto il valore attuale come minimo

        for (int j = i+1; j < array_size; j++) // Cicla sulla destra dell'indice i nell'array
        {
            if (array[j] < *min_value) // Se trova un elemento inferiore, lo setta come minimo
                min_value = &array[j];
            
        }

        if (*min_value != array[i]) // Applica lo swap solo se ha trovato valori inferiori a quello di riferimento
        {
            temp = array[i];
            array[i] = *min_value;
            *min_value = temp;
        }
    }
}
