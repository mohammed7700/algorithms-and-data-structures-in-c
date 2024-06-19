#include "primes.h"

void print_primes(int n) {

    bool isPrime[n+1];

    for (int i = 0; i <= n; i++) {
        isPrime[i] = 1;
    }
    
    for(int i = 2; i*i <= n; i++) {

        if(isPrime[i] == 1){

            for(int j = 2; i * j <= n; j++) {
                isPrime[i * j] = 0;
            }
        }
    }

    for(int i = 2; i <=n; i++) {
        if(isPrime[i] == 1) {
            printf("%i\n", i);
        }
    }
}
