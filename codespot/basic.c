#include <stdio.h>


int main(){


    // Basic operations 


    int first, second, add, subtract, multiply;
    float divide;

    printf("Enter two numbers to add, subtract, multiply and dived\n");
    scanf("%d%d \n", &first, &second);

    add = first + second;
    subtract = first - second;
    multiply = first + second;
    divide = first / (float)second; //typecasting

    printf("Addition: %d\n", add);
    printf("Subtraction: %d\n", subtract);
    printf("Multiplication: %d\n", multiply);
    printf("Division: %.2f\n", divide);

    printf("\n\n\n\n___________________\n\n\n\n");


    // Find even or odd

    int n;

    printf("Enter an integer: ");
    scanf("%d", &n);

    // Method 1
    if ((n/2)*2 == n)
        printf("Method 1: The number %d is Even\n", n);
    else
    {
        printf("Method 1: The number %d is Odd\n", n);
    }
    
    // Method 2
    if (n%2 == 0)
        printf("Method 2: The number %d is Even\n", n);
    else
    {
        printf("Method 2: The number %d is Odd\n", n);
    }
    
    printf("\n\n\n\n___________________\n\n\n\n");


    // Hello, World!

    printf("Hello, World!");


    printf("\n\n\n\n___________________\n\n\n\n");


    // Largest of threee numbers using nested if-else

    int a, b, c;

    printf("Enter the three numbers: \n");
    scanf("%d%d%d", &a, &b, &c);

    if (a < b){

        if (b<c){
            printf("Largest number is: %d", c);
        }
        else if (b > c){
            printf("Largest number is: %d", b);
        }
    }
    else
    {
        printf("Largest number is: %d", a);
    }
    
    return 0;

}