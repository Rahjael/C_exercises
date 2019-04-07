
/*  

    Inversione ordine elementi di un vettore
    Definire la funzione C che riceve in ingresso un array V di interi di dimensione N 
    ed inverte sul posto i sui valori 
    (il primo diventa ultimo e viceversa e via così per tutti gli elementi)

*/

#include <stdio.h>



void invert(int * A, int size)
{
    int temp;

    for (int i = 0; i < size; i++){
        temp = A[size-1];
        A[size-1] = A[i];
        A[i] = temp;
        size--;
    }

}



int main(void){

    int arr[5] = {5, 234, 135, 46, 453};

    int size = sizeof(arr)/sizeof(arr[0]);


    for (int i = 0; i < size; i++){
        printf("%d ", arr[i]);
    }

    invert(arr, size);

    printf("\n");

    for (int i = 0; i < size; i++){
        printf("%d ", arr[i]);
    }

}