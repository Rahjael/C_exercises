#include <stdio.h>


int main(){

    char sentence[1000];

    FILE *fptr;

    fptr = fopen("program.txt", "w");

    if (fptr == NULL)
    {
        ptinrf("Error!");
        exit(1);
    }

    printf("Enter a sentence: \n");
    gets(sentence);
    fprintf(fptr, "%s", sentence);
    fclose(fptr);





    return 0;
}