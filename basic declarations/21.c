#include <stdio.h>

int main() {

/*Write a C program that read 5 numbers 
and sum of all odd values between them*/



int numbers[4] = {0}, sum = 0;

/*
printf("Insert number a:\n");
scanf("%d", &numbers[0]);

printf("Insert number b:\n");
scanf("%d", &numbers[1]);

printf("Insert number c:\n");
scanf("%d", &numbers[2]);

printf("Insert number d:\n");
scanf("%d", &numbers[3]);

printf("Insert number e:\n");
scanf("%d", &numbers[4]);
*/


// user input

for (int i=0; i<5;i++){
    printf("Insert a number:\n");
    scanf("%d", &numbers[i]);

}

// check array for debug

for (int i=0; i<5;i++){
    printf("\n\nPosition %d, number %d\n", i+1, numbers[i]);

}


// setto = 0 tutti i numeri pari inseriti dall'utente

for (int i=0; i < 5; i++){
    if (numbers[i]%2 != 0)
        numbers[i] = numbers[i];
        else
        {
            numbers[i] = 0;
        }
}

// ristampo i numeri per debug

for (int i= 0; i<5; i++){ 
    printf("%d = %d\n ", i, numbers[i]);
}

// sommo tutti i numeri dell'array

for (int i=0; i<5; i++){ 
    sum += numbers[i];
    printf("i = %d, add %d to sum = %d\n", i, numbers[i], sum);
}


printf("The sum is %d", sum);



return 0;

}