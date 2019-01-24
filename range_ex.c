#include <stdio.h>

int main(){


    int x = 10;
    switch (x) {
        case 10 ... 49:
            printf("case 10");
            break;
        
        case 50:
            printf("case 20");
            break;
        
        default:
            printf("default case");
            break;
    }









return 0;
}