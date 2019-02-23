#include <stdio.h>

/*

Write a C program to check a given integer and return true if it is within 10 of 100 or 200.

*/

int AbsoluteDiff(int x, int y){

    if (x-y < 0){
        return ((x-y)*-1);
    }
    else
    {
        return (x-y);
    }
    
}

int Test(int x){

    if (AbsoluteDiff(x, 100) <= 10 || AbsoluteDiff(x,200) <= 10 ){
        return 1;
    }
    else
    {
        return 0;
    }
    
}


int main(){

    int n, abs;

    printf("Insert number:\n");
    scanf("%d", &n);

    printf("%d", Test(n));

    return 0;
}

