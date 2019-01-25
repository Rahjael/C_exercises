#include <stdio.h>

int main () {


// Printf function: printf("format string", var1, var2);
    
    printf("Hello world!\n\n");



// Variables declaration

    int x;
    int x = 5;
    int y, z, k;
    y = 10;
    float a = 3.5;
    char b = "A";
    char sent = "sentence";
    printf("%d, %f, %c, %c\n\n", x, a, b, sent);

// Scanf function: scanf("format string", &var);

    int age, weight;

    printf("Enter your age and weight:");
    scanf("%d, %d", &age, &weight);

    printf("Your age is %d and your weight is %d.\n\n", age, weight);


/* If, else:

    if(expression){
        statements;
    }

Operators:
<=
>=
==
!=
<
>


*/

    printf("Enter your age:");
    scanf("%d", &age);
    if (age <= 18) {
        printf("You are a minor\n");

    }
        else{
            printf("You are an adult\n");
        }


/* Arithmetic Operators:

    var1 + var2
    -
    *
    /
    %
    ++
    --
    +=
    =+
*/

    




return 0;
}