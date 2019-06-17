#include <stdio.h>



int function_name(int x)
{
    printf("\n chiamata function x");
}


int main()
{
    printf("%d", &function_name);

    return 0;
}