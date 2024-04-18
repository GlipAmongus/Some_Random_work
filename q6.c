#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool prime_boolean(int n);
void seiveEratosthene(int capacity);

int main(void)
{
    int const N = 256;

    printf("Brute Force: \n");
    for(int i = 1; i < N; i++)
    {
        if(prime_boolean(i))
            printf("%d, ", i);
    }

    printf("\nSeive of Erastosthene: ");
    seiveEratosthene(N);

    exit(0);
}

bool prime_boolean(int n)
{
    int i = 3;

    switch (n)
    {
        case 1:
            return false;
        case 2 ... 3:
            return true;
        default:
            if(n % 2 == 0)
                return false;
            while(i * i <= n)
            {
                if(n % i == 0)
                    return false;
                i = i+2;
            }
            return true;
    }
}

void seiveEratosthene(int capacity)
{
    bool prime[capacity];
    memset(prime, true, capacity);

    for(int p = 2; p*p < capacity; p++)
    {
        if(prime[p]){
            //marking multiples of prime numbers
            for(int i = p*p; i < capacity; i += p)
            {
                /*
                 * check through multiples of p at p^2 or greater
                 * since multiples of p smaller than p^2 have already been checked
                 * */
                prime[i] = false;
            }
        }
    }

    for(int p = 2; p < capacity; p++)
    {
        if(prime[p])
            printf("%d, ", p);
    }
    printf("\n");
}
