#include <stdio.h>
#include <string.h>

int main(){

    char sentence[500];

    printf("Enter a sentence:\n");

    fgets(sentence, sizeof(sentence), stdin);

    int i=0, words=1;

    while (sentence[i] != '\0'){
    
        if (sentence[i] == ' '){
            words++;
        }
        i++;
    }

    printf("Hai inserito %d parole\n", words);


    char parola[50] = "ciao";
    
    printf("\n\n%s", parola);
    printf("\n\n%s is %d", parola, strlen(parola));







    return 0;
}