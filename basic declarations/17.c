#include <stdio.h>

int main() {

int input, hours, mins, secs;

printf("Insert nummber of seconds:");
scanf("%d", &input);

hours = input/3600;
mins = (input-(hours*3600))/60;
secs = input-((mins*60)+(hours*3600));

printf("There are %d hours, %d mins and %d seconds in %d seconds.", hours, mins, secs, input);


return 0;

}