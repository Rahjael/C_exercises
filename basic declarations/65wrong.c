#include <stdio.h>

int main() {


/*
Write a C program that prints out the prime numbers between 1 and 200. 
The output should be such that each row contains a maximum of 20 prime numbers
*/

int count=0, is_prime=0, num=2;

// check nums < 200

for (; num<200;num++){

    // check if prime
    for (int divisor=2; divisor<num; divisor++){

        // exception for number 2
        if (num == 2){

            printf("%d ", num);
            count++;
        }
        // all other numbers
        else if (num%divisor != 0){

            is_prime = 1;

            // if div is not found
            if (is_prime == 1){

                is_prime = 0; // reset is_prime to false

                // check if new line is necessary
                if (count == 20){
                    printf("\n");
                    printf("%d ", num);
                    count = 1;
                }
                else
                {
                    printf("%d ", num);
                    count++;
                }
            }
            
        }

    }

}


return 0;

}