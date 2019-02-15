#include <stdio.h>
#include <string.h>

struct Record {

    unsigned int id;
    char mezzo[20];
    float spesa;
    unsigned int km;

};


int main(){

    struct Record record1, record2;

    
    FILE * p_file;

    p_file = fopen("binary_database", "wb");

  //  for (int i=0; i<2; i++){

        
        p_file = fopen("binary_database", "wb");

        /*
        printf("Inserisci Id:\n");
        scanf("%u", &record.id);
        printf("Inserisci nome automezzo:\n");
        scanf("%s", &record.mezzo);
        printf("Inserisci spesa:\n");
        scanf("%f", &record.spesa);
        printf("Inserisci km:\n");
        scanf("%u", &record.km);
*/
        printf("\n\n\n\n");

        record1.id = 2;
        strcpy(record1.mezzo, "Panda");
        record1.spesa = 342.52;
        record1.km = 32423424;

        record2.id = 5;
        strcpy(record2.mezzo, "Punto");
        record2.spesa = 18.52;
        record2.km = 123545;


        printf("%u, %s, %.3f, %u", record1.id, record1.mezzo, record1.spesa, record1.km);


        fwrite(&record1, sizeof(struct Record), 1, p_file);

        fwrite(&record2, sizeof(struct Record), 1, p_file);

    //}

    fclose(p_file);

    /*
    p_file = fopen("binary_database", "r");

        fread(&record, sizeof(struct Record), 1, p_file);*/

    return 0;
}