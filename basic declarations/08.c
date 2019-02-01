#include <stdio.h>

int main() {

int days = 1329;

int years, months, weeks;

years = days/365;
weeks = (days%365)/7;
days = days-((years*365)+(weeks*7));


printf("Years: %d; \n Months: %d; \n Weeks: %d;\n", years, weeks, days);


return 0;

}