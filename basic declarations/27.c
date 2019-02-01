#include <stdio.h>

int main() {

int array[4];


for (int i=0; i<5; i++){
    printf("Insert a positive or negative number\n");
    scanf("%d", &array[i]);
    printf("Inserito numero %d nella posizione %d dell'array\n\n", array[i], i);
}


printf("L'array è composto dai seguenti numeri:\n\n");

for (int i=0; i<5; i++){
    printf("%d - ", array[i]);
}

int positive = 0, negative = 0;

for (int i=0; i<5; i++){
    array[i] < 0 ? positive++ : negative++;

}


printf("L'array ha %d numeri positivi e %d numeri negativi", positive, negative);


return 0;

}