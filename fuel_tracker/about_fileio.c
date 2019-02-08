#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>


int main(){




    // Create file

/*

    FILE * file_pointer;


    char stuff[50] = {1};

    int index;

    file_pointer = fopen("fuel_database.txt", "w"); // create/open file

    strcpy(stuff, "Esempio blablabla");

    for (int i=1; i<10; i++) {
        fprintf(file_pointer, "%s Line number %d\n", stuff, i);
    }

    fclose(file_pointer); // close file


*/



/*
    printf("\n\nSize of stuff: %d\n\n", sizeof(stuff));
    printf("\nSize of char %d\n", sizeof(char));
    printf("Sizeof(char) * 50: %d", sizeof(char)*50);
    printf("\nSize of stuff in bytes: %d\n\n", (sizeof(stuff)*(sizeof(char))));



    for (int k=0; k<50; k++){
        printf("%c", stuff[k]);
    }
*/



    // Read file


    FILE * ptr_database;


    // Check if database exists:

    //ptr_database = fopen("database.txt", "r");

    if (fopen("database.txt", "r") == NULL)
        printf("File database.txt non trovato!");
    else
    {
        printf("File database.txt trovato.");
    }
    
    //fclose(ptr_database);

    printf("\n\n\n");


    // Writing data in various ways


    ptr_database = fopen("database.txt", "w");

    char a = 'A';
    //char string[10] = {'s','t','r','i','n'};
    
    char string[10];
    strcpy(string, "Stringa10");

    fputc(a, ptr_database);

    fputs(string, ptr_database);

    fprintf(ptr_database, "Stringa inserita con il numero 6: %d", 6);

    fclose(ptr_database);


    printf("fine prima parte\n");

    ptr_database = fopen("database.txt", "a");
    fprintf(ptr_database, "Stringa finale");

    printf("\nfine seconda parte\n");




    return 0;
}