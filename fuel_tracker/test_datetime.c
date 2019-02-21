#include <stdio.h>
#include <time.h>
#include <conio.h>


int main(){

    struct tm *local, *gm;
    time_t t;

    t = time(NULL);
    local = localtime(&t);
    printf("Local time and date using localtime function\n");
    printf("time --> %d:%d:%d\n", local->tm_hour, local->tm_min, local->tm_sec);
    printf("date --> %d/%d/%d\n", local->tm_year+1900, local->tm_mon+1, local->tm_mday);
    printf("This is the %d day of this year\n", local->tm_yday+1);
    printf("This is the %d day of this week\n", local->tm_wday+1);

    gm = gmtime(&t);
    printf("UTC time and date using gmtime function\n");
    printf("time --> %d : %d : %d\n", gm->tm_hour, gm->tm_min, gm->tm_sec);
    printf("date --> %d / %d / %d\n", gm->tm_year+1900, gm->tm_mon+1, gm->tm_mday);
    printf("This is the %d day of this year\n", gm->tm_yday+1);
    printf("This is the %d day of this week\n", gm->tm_wday);



    getchar();
    return 0;

}