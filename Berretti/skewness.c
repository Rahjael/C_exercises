#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MIN 1
#define MAX 1000
#define THRESHOLD 999

#define CAPITAL 1000000

#define WIN 15
#define LOSS 10000
#define CYCLES 100000


int get_rand(int min, int max)
{
    int num;
    num = (rand() % (max - min)+1) + min;
    return num;
}

int get_result()
{
    if( get_rand(MIN, MAX) <= THRESHOLD)
    {
        return 1;
    }
    else
    {
        return 0;
    }
    
}

int main(){

    srand(time(0));

    int net_capital = CAPITAL;
    int cycles = 0;
    int var;

    int losses = 0;
    int wins = 0;

    do
    {
        
        var = 0;

        if(get_result() == 1)
        {
            net_capital += WIN;
            var += WIN;
            wins++;
        }
        else
        {
            net_capital -= LOSS;
            var -= LOSS;
            losses++;
        }

        printf("\nCurrent capital: %d \t\t\t Variation: %d", net_capital, var);

        cycles++;

    } while (cycles < CYCLES);
    
    printf("\n\n\nCycles terminated (%d). Net result: %d \n", cycles, net_capital-CAPITAL);
    printf("\nWins: %d", wins);
    printf("\nLosses: %d", losses);
    return 0;
}