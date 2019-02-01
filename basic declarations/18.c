#include <stdio.h>

int main() {

int input, years, months, days;

printf("Insert number of days:");
scanf("%d", &input);

years = input/365;
months = (input-(years*365))/30;
days = input-((months*30)+(years*365));


printf("There are %d years, %d months and %d days in %d days", years, months, days, input);


return 0;

}