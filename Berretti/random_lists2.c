#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int get_random_number(int min, int max)
{
    int num;
    num = (rand() % (max-min)) + min;
            
    return num;

}



int main()
{


    srand(time(0));

    for(int i=0; i < 20; i++)
    {
        printf("%d - ", get_random_number(0, 100));
    }

    return 0;
}