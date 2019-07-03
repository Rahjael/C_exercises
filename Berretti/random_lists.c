#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{

    int lower = 5;
    int upper = 7;
    int count = 1;


    srand((unsigned int)time(0));

    for(int i=0; i < count; i++)
    {
        int num = (rand() % (upper - lower +1 )) + lower;
        printf("%d");
    }









    return 0;
}