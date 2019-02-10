#include <stdio.h>
//#include <stdlib.h>

int main(){

    char string[50];

    printf("Input a string:\n");
    fgets(string, sizeof(string), stdin);
    
    printf("Stringa: %s", string);



    return 0;
}