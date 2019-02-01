#include <stdio.h>

int main() {


int amount, note100, note50, note20, note10, note5, note2, note1;

printf("Insert an amount:");
scanf("%d", &amount);


note100 = amount/100;
printf("%d - %d\n", amount, note100);

note50 = (amount-note100*100)/50;
printf("%d - %d\n", amount, note50);

note20 = (amount-((note100*100)+(note50*50)))/20;
printf("%d - %d\n", amount, note20);

note10 = (amount-((note100*100)+(note50*50)+(note20*20)))/10;
printf("%d - %d\n", amount, note10);

note5 = (amount-((note100*100)+(note50*50)+(note20*20)+(note10*10)))/5;
printf("%d - %d\n", amount, note5);

note2 = (amount-((note100*100)+(note50*50)+(note20*20)+(note10*10)+(note5*5)))/2;
printf("%d - %d\n", amount, note2);

note1 = amount-((note100*100)+(note50*50)+(note20*20)+(note10*10)+(note5*5)+(note2*2));
printf("%d - %d\n", amount, note1);

printf("There are: \n\n %d note(s) of 100\n %d note(s) of 50\n %d note(s) of 20\n %d note(s) of 10\n %d note(s) of 5\n %d note(s) of 2\n %d note(s) of 1\n ", note100, note50, note20, note10, note5, note2, note1);





return 0;

}