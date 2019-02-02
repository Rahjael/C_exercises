#include <stdio.h>

/*
Write a C program to read a password until it is correct. 
For wrong password print "Incorrect password" and for correct 
password print "Correct password" and quit the program. 
The correct password is 1234.
*/


int main() {

int input;

printf("Insert password:\n");
scanf("%d", &input);

while (input != 1234){
    printf("Incorrect password.");
    printf("Insert password:\n");
    scanf("%d", &input);
}

printf("Correct password");


return 0;

}