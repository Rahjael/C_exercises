#include <stdio.h>



/*
void function(int var[]){

    var[0] = 10;

    return;

}
*/



int main(){

/*
    int var[] = {5, 6};


    printf("Var pre fuction: %d\n", var[0]);
    printf("Call function()...\n");

    function(var);


    printf("Var post function: %d", var[0]);
*/



/*
    int * ptr;
    int * ptr2;
    int value = 5;

    *ptr = value;
    ptr2 = &value;

    printf("\nPtr: %d", ptr);
    printf("\n&ptr: %d", &ptr);
    printf("\n*ptr: %d", *ptr);
    printf("\nvalue: %d", value);
    printf("\n&value: %d", (int *)&value);
    printf("\nptr2: %d", ptr2);

*/


    int arr[5] = {45, 2, 345, 43, 6};

    printf("\n arr: \t%d", arr);
    printf("\n &arr[0]: \t%d", &arr[0]);
    printf("\n &arr: \t%d", &arr);
    printf("\n arr[2]: \n%d", arr[2]);
    printf("\n *(arr+2): \t%d", *(arr+2));


}