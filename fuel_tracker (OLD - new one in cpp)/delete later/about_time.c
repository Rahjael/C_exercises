#include <stdio.h>
#include <time.h>


int main(){

    time_t current_epoch;

    int minutes, hours, days, years;

    current_epoch = time(NULL);

    minutes = current_epoch/60;
    hours = current_epoch/3600;
    days = current_epoch/(3600*24);
    years = current_epoch/(3600*24*365);

    printf("Seconds since epoch: %d \n", current_epoch);
    printf("Hours since epoch: %d\n", hours);
    printf("Days since epoch: %d \n", days);
    printf("Years since epoch: %d ", years);




}