#include <stdio.h>
#include <time.h>


int main() {

time_t normvar;
normvar = time(NULL);

// Oppure:

time_t * ptrvar;
time(ptrvar);

printf("Normal variable value: %ld\n", normvar);
printf("Pointer variable value: %ld\n", *ptrvar);
printf("Pointer: %ld\n", ptrvar);
printf("Pointer address: %ld\n", &ptrvar);

printf("\n\n\n\n");



return 0;

}