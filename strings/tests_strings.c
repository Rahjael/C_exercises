#include <stdio.h>
#include <string.h>

int main(){

/*    int num1, num2, cycle=1;

    do{
        printf("Insert 2 numbers (0 to exit):\n");
        scanf("%d", &num1);
        scanf("%d", &num2);
        printf("Nums are: %d, %d", num1, num2);
        cycle++;
        printf("\nCycle %d\n", cycle);
    } while(num1 != 0);
*/

    char array[4]="ciao";

    printf("Num is %s, length is %d\n", array, strlen(array));

    array[0] += 1;

    printf("Num is %s, length is %d\n", array, strlen(array));

    int num = 3456;

    printf("Num is %d\n", num);
    
    char nume[5] = num;

    printf("Num is %s\n", nume);


    return 0;
}



