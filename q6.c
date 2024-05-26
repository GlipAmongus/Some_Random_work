#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool prime_boolean(int n);
void sieveEratosthene(int capacity);

int main(void)
{
    int const N = 251;
    printf("Check for primes up to: %d\n", N);

    printf("Brute Force: \n");
    for(int i = 1; i <= N; i++)
    {
        if(prime_boolean(i))
            printf("%d, ", i);
    }

    printf("\nSieve of Eratosthene: \n");
    sieveEratosthene(N);

    exit(0);
}

bool prime_boolean(int n)
{
    if(n == 1)
        return false;
    for(int i = 2; i <= n; i++)
    {
        if((n % i == 0) && (n != i))
            return false;
    }
    return true;
}

void sieveEratosthene(int capacity)
{
    bool prime[capacity];
    memset(prime, true, capacity);
    for(int p = 2; p*p <= capacity; p++)
    {
        if(prime[p-1]){
            //marking multiples of prime numbers
            for(int i = p*p; i <= capacity; i += p)
                /* check through multiples of p at p^2 or greater
                 * since multiples of p smaller than p^2 have already been checked */
                prime[i-1] = false;
        }
    }
    for(int p = 2; p <= capacity; p++)
    {
        if(prime[p-1])
            printf("%d, ", p);
    }
    printf("\n");
}