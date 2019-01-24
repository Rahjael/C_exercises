#include <stdio.h>

int main() {


    char ch;
    printf("Please enter an alphabetical character \n\n");
    scanf("%c", &ch);

    switch (ch){
        case 'A' ... 'Z':
            printf("%c is in Uppercase", ch);
            break;
        case 'a' ... 'z':
            printf("%c is in Lowercase", ch);
            break;



    }



return 0;

}