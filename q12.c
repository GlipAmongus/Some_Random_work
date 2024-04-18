#include <stdlib.h>
#include <stdio.h>
#include <time.h>

unsigned long long int sumFibonacci(int i);

int main(void)
{
    //unique seed value
    srand(time(NULL));

    int n = (rand() % 127) + 2;

    unsigned long long int sum = sumFibonacci(n);

    printf("Sum of the first %d numbers: %llu", n, sum);

    exit(0);
}

unsigned long long int sumFibonacci(int i)
{
    int sum = 2;
    int x = 1;
    int y = 1;
    int z;

    if(i >= 2) {
        for (int j = 2; j < i; j++) {
            z = x + y;
            x = y;
            y = z;
            sum += z;
        }
        return sum;
    }

    return 0;
}
