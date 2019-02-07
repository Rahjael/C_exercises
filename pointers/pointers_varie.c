#include <stdio.h>



int main(){


/*
    int first, second, *p, *q, sum;
    
    printf("Enter at least a two numbers to add\n");
    scanf("%d%d", &first, &second);
    
    p = &first;
    q = &second;
    
    sum = *p + *q;
    
    printf("Sum using pointers: %d\n", *p+*q);
    printf("Sum using two normal variables:%d\n", first+second);
    printf("Sum using single variable: %d\n", sum);
    printf("Sum using complex internal decl: %d\n", int * p =&first )

*/


/*
    int num1, num2, *first, *second;

    printf("Enter two integers to sum:\n");
    scanf("%d %d", &num1, &num2);

    printf("Somma dei due valori usando due puntatori: %d", (*(first = &num1)+*(second = &num2)));
*/



    int array[5]={0}, *pointer;

    
    pointer = &array[0];

    printf("\n\nCon pointer = &array[0]\n\n");
    printf("Pointer: %d\n", pointer);
    printf("*pointer: %d\n", *pointer);
    printf("&array: %d\n", &array);
    printf("&array[0]: %d\n", &array[0]);
    printf("array: %d\n", array);


    pointer = *&array;

    printf("\n\nCon pointer = *&array\n\n");
    printf("Pointer: %d\n", pointer);
    printf("*pointer: %d\n", *pointer);
    printf("&array: %d\n", &array);
    printf("&array[0]: %d\n", &array[0]);
    printf("array: %d\n", array);

    pointer = *(&array);

    printf("\n\nCon pointer = *(&array)\n\n");
    printf("Pointer: %d\n", pointer);
    printf("*pointer: %d\n", *pointer);
    printf("&array: %d\n", &array);
    printf("&array[0]: %d\n", &array[0]);
    printf("array: %d\n", array);



    pointer = array;

    printf("\n\nCon pointer = array\n\n");
    printf("Pointer: %d\n", pointer);
    printf("*pointer: %d\n", *pointer);
    printf("&array: %d\n", &array);
    printf("&array[0]: %d\n", &array[0]);
    printf("array: %d\n", array);


/*





int n,i,*ptr,sum=0;
    printf("Enter number of elements: \n");
    scanf("%d",&n);

    ptr=(int*)malloc(n*sizeof(int));
    if(ptr==NULL)
    {
        printf("Error! memory not allocated.");
        return 0;
    }
 
    printf("Enter elements of array: \n");
    for(i=0;i<n;++i)
    {
        scanf("%d",ptr+i);
        sum+=*(ptr+i);
    }
 
    printf("Elements of array entered : ");
    for(i = 0;i<n; i++)
    {
        printf("%d ",ptr[i]);
    }

    free(ptr);

*/




/*

const int MAX = 5;
 
int main() {
 
  char *names[] = { "Dhoom", "Movie", "Music", "Computer", "Radio"};
  int i = 0;
 
  for (i = 0; i < MAX; i++) {
 
    printf("Value of names[%d] = %s\n", i, names[i]);
 
  }


*/


    return 0;
}