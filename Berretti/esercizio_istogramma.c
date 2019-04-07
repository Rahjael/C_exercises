/*

    Istogramma di un vettore
    Definire la funzione C che riceve in ingresso un array V di valori interi di dimensione N 
    e genera un array W che rappresenta l'istogramma di V. 
    W deve cioè contenere per ognuno dei valori distinti di
    V il valore ed il numero di occorrenza del valore nel vettore

*/

#include <stdio.h>
#include <stdlib.h>

#define VALUES {3, 4, 5, 2, 1, 2, 5, 2, 1, 3, 3, 2, 1, 4, 3, 1, 2, 3}

int create_histogram(int * original_array, int * histogram, int orig_size)
{
    int index_orig = 0;
    int index_histo = 0;
    int histo_size = 0;

    
    for (; index_orig < orig_size; index_orig++) // itera su ogni elemento di original_array
    {
        short done = 0; // Imposta un check per vedere se il valore è già stato inserito nell'array di output

        for (int check = index_histo; check >= 0; check-=2)
        {
            if(histogram[check] == original_array[index_orig])
            {
                done = 1;
                break;
            }
        }

        if (done == 0) // se quel valore non è stato trovato ne conto le occorrenze e lo inserisco nell'istogramma
        {
            //
            // In questo blocco rialloco la memoria con la nuova dimensione
            // Copio l'array in un altro di appoggio e poi lo copio di nuovo, aumentato
            //

            histo_size += 2; // assegno due slot all'array di ouput

            int * new_histo = (int *)malloc(histo_size*sizeof(int)); // Creo lo spazio di appoggio

            for (int new = 0; new < histo_size-2; new++) // copio i valori nell'appoggio
                new_histo[new] = histogram[new];

            for (int i = 0; i<histo_size-2; i+=2)
                printf("newhisto %d | %d\n", new_histo[i], new_histo[i+1]);


            
            histogram = (int *)malloc(histo_size*sizeof(int)); // creo il nuovo array

            for (int new = 0; new < histo_size-2; new++) // trasferisco dall'appoggio all'array
                histogram[new] = new_histo[new];
            
            for (int i = 0; i<histo_size-2; i+=2)
                printf("histo %d | %d\n", histogram[i], histogram[i+1]);


            free(new_histo);

            //
            // Fine del blocco di riallocazione
            //
            //

            // conto le occorrenze in original_array:
            int how_many = 0;

            for (int j = 0; j < orig_size; j++)
            {
                if (original_array[index_orig] == original_array[j])
                {
                    how_many++;
                }
            }

            histogram[index_histo] = original_array[index_orig];
            histogram[index_histo+1] = how_many;
            index_histo += 2; // dopo aver registrato i valori in histogram, aumento l'index di 2
        }
    }

    return histo_size;

}


int main(void){

    int arr[] = VALUES;

    int size = sizeof(arr)/sizeof(arr[0]);

    int * histogram;

    int histo_size = create_histogram(arr, histogram, size);


    // Stampa l'istogramma

    for (int i = 0; i<histo_size; i+=2){
        printf("%d | %d\n", histogram[i], histogram[i+1]);
    }





}