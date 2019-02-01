#include <stdio.h>

int main() {


float weight1, weight2, num1, num2, avg;

printf("Insert first item's weight:\n");
scanf("%f", &weight1);
printf("Insert second item's weight:\n");
scanf("%f", &weight2);
printf("Insert how many first item:\n");
scanf("%f", &num1);
printf("Insert how many second item:\n");
scanf("%f", &num2);

avg = ((weight1*num1)+(weight2*num2))/(num1+num2);



printf("Average value is %f", avg);


return 0;

}