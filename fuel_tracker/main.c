#include <stdio.h>
#include <string.h>

#define DATABASE_NAME "database"


struct Record {

    unsigned int id;
    char vehicle[50];
    float amount;
    unsigned int km;
    

};



int CountDatabaseEntries();



int main(){

    // Check if database exists. If it doesn't, create it.

    FILE * p_database;

    if(!(p_database = fopen(DATABASE_NAME, "r"))){
        
        printf("### Database inesistente. Lo creo.\n");
        
        fopen(DATABASE_NAME, "wb");
        
        printf("### Database creato.\n");
    }
    else
    {
        printf("### Database rilevato.\n");
    }
    
    fclose(p_database);


    return 0;
}








int CountDatabaseEntries(){

    int entries=0;

    struct Record temp_record;

    FILE * p_file;

    p_file = fopen(DATABASE_NAME, "rb");

    fseek(f,0)




    return entries
}