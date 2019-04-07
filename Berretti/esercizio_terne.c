
/*
    Terne consecutive di un vettore
    Definire la funzione C che riceve in ingresso un vettore di numeri interi 
    e stampa le terne consecutive la cui somma è maggiore della media dei valori del vettore.
    Le terne devono poter essere concatenate.
*/




#include <stdio.h>

#define VALUES {35, 24, 25, 75, 36, 36, 49, 14, 56, 96, 45, 56, 85, 85, 24}



void print_terne(int * arr, int size){

    // Se size non è multiplo di tre interrompe la funzione
    if (size%3 != 0){
        printf("\nArray non valido. La dimensione (%d) non è multiplo di 3", size);
        return;
    }

    int sum = 0;
    int avg;
    int terna_sum;

    // somma i valori dentro l'array
    for (int i = 0; i < size ; i++){
        sum += arr[i];
    }

    // trova la media
    avg = sum/size;

    // Stampa le terne se la loro somma è maggiore di 
    for (int i=0; i<size; i += 3){
        terna_sum = arr[i] + arr[i+1] + arr[i+2];
        if(terna_sum > avg){
            printf("\nLa somma di (%d, %d, %d) è superiore alla media (avg: %d, sum=%d) ", arr[i], arr[i+1], arr[i+2], avg, terna_sum);
        }
    }

}



int main(void){

    int main_array[] = VALUES;

    int size = sizeof(main_array)/sizeof(main_array[0]);

    print_terne(main_array, size);

    return 0;
}