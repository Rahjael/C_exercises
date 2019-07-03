#include <stdio.h>

typedef int boolean;
#define TRUE 1
#define FALSE 0

void bubbleSort(float* A, int length, int* pSwaps, int* pCycles){
    int cycles = 0;
    int swaps = 0;

    for(int k=length-1; k>0; k--)
    {
        boolean swap = FALSE;
        for(int i=0; i<k; i++){
            cycles++;
            if(A[i]>A[i+1])
            {
                float tmp = A[i+1];
                A[i+1] = A[i];
                A[i] = tmp;
                swaps++;
                swap=TRUE;
            }
        }
        // if no swap in the inner cycle: sarray is already sorted!
        if(!swap)
            break;
    }
    if(pSwaps != NULL)
        *pSwaps = swaps;
    if(pCycles != NULL)
        *pCycles = cycles;
}



// Implementazione di una variant dal libro "Fondamenti di programmazione" (Enrico Vicario),
// al termine della spiegazione sul bubble sort.
void bubbleSortOpt(float* A, int length, int* pSwaps, int* pCycles){
    int cycles = 0;
    int swaps = 0;

    int first = 0;
    int last = length-1;
    while(last-first > 0)
    {

        boolean swap = FALSE;
        for(int i=first; i<last; i++){
            cycles++;
            if(A[i]>A[i+1])
            {
                float tmp = A[i+1];
                A[i+1] = A[i];
                A[i] = tmp;
                swaps++;
                swap=TRUE;
            }
        }
        last--;
        // if no swap in the inner cycle: sarray is already sorted!
        if(!swap)
            break;

        swap = FALSE;
        for(int i=last; i>first; i--){
            cycles++;
            if(A[i-1]>A[i])
            {
                float tmp = A[i-1];
                A[i-1] = A[i];
                A[i] = tmp;
                swaps++;
                swap=TRUE;
            }
        }
        first++;
        // if no swap in the inner cycle: sarray is already sorted!
        if(!swap)
            break;
    }
    if(pSwaps != NULL)
        *pSwaps = swaps;
    if(pCycles != NULL)
        *pCycles = cycles;
}


void printArray(float* A, int length){
    if(length==0)
        printf("[]");
    else {
        printf("[");
        for (int i = 0; i < length; i++)
            printf("%f, ", A[i]);
        printf("\b\b");
        printf("]\n");
    }
}



int main() {
    int cycles;
    int swaps;
    int n = 10;

    float A[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    printf("Array:  ");
    printArray(A, n);
    bubbleSort(A, n, &swaps, &cycles);
    printf("Sorting with bubble-sort, %d inner cycles and %d swaps.\n", cycles, swaps);
    printf("Sorted: ");
    printArray(A, n);

    printf("\n");

    float A1[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    printf("Array:  ");
    printArray(A1, n);
    bubbleSortOpt(A1, n, &swaps, &cycles);
    printf("Sorting with optimized-bubble-sort, %d inner cycles and %d swaps.\n", cycles, swaps);
    printf("Sorted: ");
    printArray(A1, n);

    printf("\n\n\n\n\n");


    float B[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0};
    printf("Array:  ");
    printArray(B, n);
    bubbleSort(B, n, &swaps, &cycles);
    printf("Sorting with bubble-sort, %d inner cycles and %d swaps.\n", cycles, swaps);
    printf("Sorted: ");
    printArray(B, n);

    printf("\n");

    float B1[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0};
    printf("Array:  ");
    printArray(B1, n);
    bubbleSortOpt(B1, n, &swaps, &cycles);
    printf("Sorting with optimized-bubble-sort, %d inner cycles and %d swaps.\n", cycles, swaps);
    printf("Sorted: ");
    printArray(B1, n);


    printf("\n\n\n\n\n");

    float C[] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    printf("Array:  ");
    printArray(C, n);
    bubbleSort(C, n, &swaps, &cycles);
    printf("Sorting with bubble-sort, %d inner cycles and %d swaps.\n", cycles, swaps);
    printf("Sorted: ");
    printArray(C, n);

    printf("\n");

    float C1[] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    printf("Array:  ");
    printArray(C1, n);
    bubbleSortOpt(C1, n, &swaps, &cycles);
    printf("Sorting with optimized-bubble-sort, %d cycles and %d swaps.\n", cycles, swaps);
    printf("Sorted: ");
    printArray(C1, n);



    return 0;
}

