#include <stdio.h>
#define ARRAY_SIZE 5

/* Testing area for pointers stuff */


int main(){

    //
    //
    // THE VERY BASICS
    //
    //

    int normvar_a;

    printf("//\n//\n//\n");
    printf("// BASIC STUFF\n");
    printf("//\n//\n//\n");


    printf("Inserisci un valore per normvar_a:");
    scanf("%d", &normvar_a);

    printf("Norvar_a = %d\n", normvar_a);

    printf("Adesso creo un puntatore a normvar_a.\n");
    
    int * ptr_a = &normvar_a;

    printf("Creato ptr_a su normvar_a.\n"
    
    "Puntatore ptr_a value: %d\n"
    "Normvar_a value: %d\n"
    "Normvar_a address: %d\n"
    "Dereferencing puntatore ptr_a: %d\n"
    "Address di ptr_a: %d\n"

    , ptr_a, normvar_a, &normvar_a, *ptr_a, &ptr_a);


    //
    //
    // SIZEOF
    //
    //
    printf("//\n//\n//\n");
    printf("// SIZES\n");
    printf("//\n//\n//\n");

    printf("Size of normvar_a: %d\n", sizeof(normvar_a));
    printf("Size of ptr_a: %d\n", sizeof(ptr_a));
    printf("Size of &norvar_a: %d\n", sizeof(&normvar_a));
    printf("Size of *ptr_a: %d\n", sizeof(*ptr_a));
    printf("Size of &ptr_a: %d\n", sizeof(&ptr_a));

    printf("\n\n");

    //
    //
    // ON THE SUBJECT OF ARRAYS
    //
    //

    
    printf("//\n//\n//\n");
    printf("// ARRAYS\n");
    printf("//\n//\n//\n");

    int array[ARRAY_SIZE];

    printf("Array di int creato ma non inizializzato.\n");
    printf("Printo i valori casuali contenuti:\n");
    
    for (int i=0; i < ARRAY_SIZE; i++){
        printf("array[%d] = %d\n", i, array[i]);
    }

    printf("\n\n\n");

/*
    printf("//\n//\n//\n");
    printf("// Popolare array tramite for:\n");
    printf("//\n//\n//\n");

    printf("Inserire %d valori per l'array:\n", ARRAY_SIZE);

    for (int i=0; i < ARRAY_SIZE; i++){
        printf("Inserisci valore per la posizione %d:\n", i);
        scanf("%d", &array[i]);
        printf("Inserito valore %d nella posizione %d\n", array[i], i);

    }
*/


    printf("Inserisco i valori 1, 2, 3, 4, 5 nell'array:\n\n\n");

    for (int i=0; i<ARRAY_SIZE; i++){
        array[i] = i+1;
    }


    printf("\n\n\nL'array contiene adesso i valori:\n");

    for (int i=0; i < ARRAY_SIZE; i++){
        printf("array[%d] = %d\n", i+1, array[i]);
    }

    printf("//\n//\n//\n");
    printf("// Modificare array tramite puntatori:\n");
    printf("//\n//\n//\n");


    // point to array
    int * ptr_array = array;

    printf("\n\nGenerato ptr_array. Mostro vari valori:\n\n");

    printf("array[0]: %d\n", array[0]);
    printf("&array[0]: %d\n", &array[0]);
    printf("array: %d\n", array);
    printf("ptr_array: %d\n", ptr_array);
    printf("*ptr_array: %d\n", *ptr_array);

    printf("\n\n\n\n");

    printf("\nAdesso visualizzo tutti i valori in più modi:\n");


    printf("\nValori array attuale (normal):");
    for (int i=0; i<ARRAY_SIZE; i++){
        printf("%d ", array[i]);
    }

    printf("\nValori array attuale (ptr_array):");
    for (int i=0; i<ARRAY_SIZE; i++){
        printf("%d ", *ptr_array+i);
    }

    printf("\n\n");

    printf("\nAddresses array attuale (normal):");
    for (int i=0; i<ARRAY_SIZE; i++){
        printf("%d ", &array[i]);
    }

    printf("\nAddresses array attuale (ptr_array):");
    for (int i=0; i<ARRAY_SIZE; i++){
        printf("%d ", ptr_array+i);
    }


    printf("\n\n\n");


    printf("Adesso moltiplico tutti i valori per x 2 usando la \"normale\" manipolazione array:\n\n\n");

    printf("Array x 2 (normal):");

    for (int i=0; i<ARRAY_SIZE; i++){
        printf("%d ", (array[i] *= 2) );
    }

    printf("\n\nRiprinto per verificare:\n");

    printf("\nValori array attuale (normal):");
    for (int i=0; i<ARRAY_SIZE; i++){
        printf("%d ", array[i]);
    }

    printf("\nAdesso rimoltiplico x2 i valori, usando i puntatori:\n");
    printf("\nValori array x2 (x2):");
    for (int i=0; i<ARRAY_SIZE; i++){
        printf("%d ", *(ptr_array+i)*=2 );
    }

    return 0;
}