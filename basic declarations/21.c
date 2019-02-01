#include <stdio.h>

int main() {

/*Write a C program that read 5 numbers 
and sum of all odd values between them*/



int numbers[4], sum = 0;


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



for (int i=0; i < 5; i++){  // setto = 0 tutti i numeri pari inseriti dall'utente
    if (numbers[i]%2 != 0)
        numbers[i] = numbers[i];
        else
        {
            numbers[i] = 0;
        }
}

for (int i= 0; i<5; i++){ // stampo i numeri per debug
    printf("%d = %d\n ", i, numbers[i]);
}

for (int i=0; i<5; i++){ // sommo tutti i numeri dell'array
    sum += numbers[i];
    printf("i = %d, add %d, to sum = %d\n", i, numbers[i], sum);
}


printf("The sum is %d", sum);



return 0;

}