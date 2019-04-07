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

int create_histogram(int * original_array, int * histogram, int orig_size, int histo_size)
{

    // Inizializzo a 0 gli indici e i contatori che mi serviranno dopo
    int index_orig = 0;
    int index_histo = 0;
    int final_size = 0;
    int how_many;


    for (; index_orig < orig_size; index_orig++) // itera su ogni elemento di original_array
    {
        short done = 0; // Imposta un check per vedere se il valore è già stato inserito nell'array di output

        for (int check = index_histo; check >= 0; check-=2) // cicla sul nuovo array per vedere se quel valore è già stato contato
        {
            if(histogram[check] == original_array[index_orig]) // Se è già stato contato, interrompi e vai avanti
            {
                done = 1;
                break;
            }
        }

        if (done == 0) // se quel valore non è stato trovato ne conto le occorrenze e lo inserisco nell'istogramma
        {
            final_size++; // aumento di uno il contatore di valori singoli

            how_many = 0; // azzero il contatore di occorrenze

            for (int j = 0; j < orig_size; j++) // ciclo l'array originale per contare le occorrenze
            {
                if (original_array[index_orig] == original_array[j])
                {
                    how_many++; // aumento il contatore per ogni valore uguale che trovo
                }
            }

            // assegno il valore e il numero di occorrenze:
            histogram[index_histo] = original_array[index_orig];
            histogram[index_histo+1] = how_many;
            index_histo += 2; // dopo aver registrato i valori in histogram, aumento l'index di 2
        }
    }

    return final_size<<1; // ritorno il numero effettivo di valori presi singolarmente, raddoppiato
}

int main(void){

    int arr[] = VALUES;

    int size = sizeof(arr)/sizeof(arr[0]);
    int histo_size = size<<1;

    int * histogram = (int*)malloc(histo_size*sizeof(int)); // creo un target array grande il doppio, come worst case

    // creo l'istogramma e ne assegno la dimensione effettiva
    int final_size = create_histogram(arr, histogram, size, histo_size);


    // In questo blocco rialloco la memoria con la nuova dimensione
    // per evitare di occupare N*2 memoria quando non necessario
    // e pulire la stampa finale
        int * temp_array = (int *)malloc((final_size)*sizeof(int)); // Creo lo spazio di appoggio

        for (int new = 0; new < (final_size); new++) // copio i valori nell'appoggio
            temp_array[new] = histogram[new];

        free(histogram);

        histogram = (int *)malloc((final_size)*sizeof(int)); // creo il nuovo array

        for (int new = 0; new < (final_size); new++) // trasferisco dall'appoggio all'array
            histogram[new] = temp_array[new];

        free(temp_array);
    //
    // Fine del blocco di riallocazione
    //



    // Stampa l'istogramma
    printf("\nValore | Nr occorrenze: \n");
    for (int i = 0; i<(final_size); i+=2){
        printf("%d | %d\n", histogram[i], histogram[i+1]);
    }

    return 0;

}