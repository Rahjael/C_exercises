#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>



void DatabaseCheck();
void Separatori();
void ReadFromDatabase();



int main(){


    FILE * ptr_database;

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


    DatabaseCheck();

    ReadFromDatabase();

    return 0;

}


    // Read file


void DatabaseCheck(){

    FILE * ptr_database; // Lo metto qui o nel main? Unsure.

    // Check if database exists:

    ptr_database = fopen("database.txt", "r");

    if (ptr_database == NULL)
    {

        Separatori();
        printf("### File database.txt non trovato! Primo avvio?\n");
        Separatori();
        fclose(ptr_database);
        printf("### Creo database\n");

        ptr_database = fopen("database.txt", "w");

        fclose(ptr_database);

        Separatori();
        printf("### Database creato\n");

    }
    else
    {
        Separatori();
        printf("### File database.txt trovato.\n");
        Separatori();

    }
    

    fclose(ptr_database);

    printf("\n\n\n");

    printf("\nFine di DatabaseCheck()\n");


}


void ReadFromDatabase(){

    FILE * ptr_database;

    ptr_database = fopen("mock_database.txt", "r");

    char db_line[50];

    int c, i = 0;

    while (c=fgetc(ptr_database) != EOF){

        db_line[i] = c;
        i++;
    }

    printf("Stringa: %s\n", db_line);


/*
    while (fgetc(ptr_database) != EOF){

        fgetc(db_line, sizeof(db_line), ptr_database);

        // printf("String: %s\n", db_line);
        printf("FIrst char: %c\n", db_line[0]);

    }
*/


    fclose(ptr_database);
}




void Separatori(){
    printf("###\n###\n###\n");
}









/*

    // Writing data in various ways


    ptr_database = fopen("database.txt", "w");

    char a = 'A';
    
    char string[10];

    strcpy(string, "Stringa10");

    fputc(a, ptr_database);

    fputs(string, ptr_database);

    fprintf(ptr_database, "\nStringa inserita con il numero 6: %d", 6);


    fclose(ptr_database);


    printf("fine prima parte\n");

    ptr_database = fopen("database.txt", "a");
    fprintf(ptr_database, "\nStringa finale");

    printf("\nfine seconda parte\n");

*/