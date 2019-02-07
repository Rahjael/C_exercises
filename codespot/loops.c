#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main(){


    // Do-while loop example

    int i = 5;

    do{
        printf("Hello World %d\n", i);
        i = i-1;
    } while (i>0);



    // Even and odd using & operator

    int x;

    for(x=0; x<=5;x++){

        if(x&1)
            printf("%d - odd\n", x);
        else
            printf("%d - even\n", x);
    }


    // For Loop

    int k;

    for (k=0; k<5;k++)
        printf("%d\n", k);




    int a, b;

    srand(time(NULL));

    while (1) {
        a = rand() % 20;
        printf("%d\n", a);
        
        if (a == 10)
            break;

        b = rand() % 20;
        printf("%d\n", b);        

    }


    int j;

    printf("Output of nested loop is: \n");
    for (i=0; i<3; i++)
    {
        for(j=0; j<3;j++)
        {
            printf("%d \n", i+j);
        }
    }



    return 0;
}