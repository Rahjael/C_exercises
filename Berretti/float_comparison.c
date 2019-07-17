#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#define PRECISION .000000119
#define TRUE 1
#define FALSE 0

typedef unsigned short int Boolean;

Boolean is_equal(float a, float b)
{
    float diff = fabs(a-b); // valore assoluto della differenza
    a = fabs(a);
    b = fabs(b);
    float largest = b > a ? b : a;

    if(diff <= largest * PRECISION)
    {
        return TRUE;
    }
    else
    {
        return FALSE;
    }
    
}

