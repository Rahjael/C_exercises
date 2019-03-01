#include <stdio.h>
#include <conio.h>

int main(){

    char lettera;

    do{
    
        printf("Inserisci lettera:\n");
        scanf(" %c", &lettera);

        printf("\nLettera: %c\n", lettera);

    }while( lettera != 's');

    return 0;

}