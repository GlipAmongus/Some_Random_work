#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <math.h>

long double cosine(int N, double x);
long double factorial(int n);

int main(void)
{
    const int N = 8;

    //unique seed value
    srand(time(NULL));

    long double cosine_approx = cosine(N, M_PI);

    printf("For n = %d\n", N);
    printf("Mclaurin Expansion of cosine: %Lf\n", cosine_approx);

    exit(0);
}

long double cosine(int N, double x)
{
    long double expansion = 0;
    for(int n = 0; n < N; n++)
    {
        expansion += (pow(-1, n)/factorial(2*n))*(pow(x, 2*n));
    }
    return expansion;
}

long double factorial(int n)
{
    int result = 1;
    for (int i = 1; i <= n; i++)
    {
        result *= i;
    }
    return (long double)result;
}