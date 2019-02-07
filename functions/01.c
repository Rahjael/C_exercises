#include <stdio.h>
#include <stdlib.h>

int Addition(int, int);


int main(){

 

    int outnum1, outnum2, sum;

    printf("Insert 2 numbers to add: \n");
    scanf("%d%d", &outnum1, &outnum2);

    // sum = Addition(outnum1, outnum2);

    printf("%d", Addition(outnum1, outnum2));


    getchar();

    return 0;
}


int Addition(int num1, int num2){
    
    return num1 + num2;

}   

