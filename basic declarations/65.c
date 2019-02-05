#include <stdio.h>
#define MAX 200

int main() {

/*
Write a C program that prints out the prime numbers between 1 and 200. 
The output should be such that each row contains a maximum of 20 prime numbers
*/

int num, count, is_prime=0;

// initialize 1 and 2 as primes
printf("1 2 ");
count=2;

// check for every number after 2
for (num=3; num<=MAX; num++){

    // prime check
    for (int i=2; i<num; i++){
        
        // if not prime, stop checking and go to next num
        if (num%i == 0){
            is_prime = 0;
            break;
        }
        is_prime = 1;
    }

    // if prime, print it
    if (is_prime == 1){
        
        // check line. If 10 numbers already printed, go to new line
        if (count == 10){            
            printf("\n");
            count = 0;
        }

        printf("%d ", num);
        count++;
    }

}


return 0;

}