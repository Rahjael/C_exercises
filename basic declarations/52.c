#include <stdio.h>
#define NUM 6

int main() {

/*
Write a C program to read an array of length 6 
and find the smallest element and its position.
*/

int array[NUM], smallest, pos, init=0;

for (int i=0; i<NUM;i++){
    printf("Insert a number:\n");
    scanf("%d", &array[i]);
    if (init==0)
        init=1, smallest=array[i], pos=i;
    //(init == 0) ? init=1, smallest = array[i], pos = i : smallest;
    if (array[i] < smallest){
        smallest = array[i];
        pos = i;
    
    }
}

printf("Smallest number is %d, in position %d of the array", smallest, pos+1);



return 0;

}





/*
Mi rendo conto che scritto così potrei in realtà aggiustarlo e fare anche a meno dell'array, e come soluzione dell'esercizio è sbagliata perché lui mi dice espressamente di leggere l'array e io di fatto non lo faccio.

Però mi ero rotto il cazzo di scrivere sequenze di for, e quindi ho provato una soluzione diversa con l'operatore ternario (che mi risolve il problema di inizializzare la variabile "smallest" al primo ciclo, senza creare conflitti con un qualsiasi integer che l'utente possa inserire). Che ne pensi?
*/