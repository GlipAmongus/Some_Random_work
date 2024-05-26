#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <float.h>

long double cosine(int N, double x);
long double sine(int N, double x);
long double factorial(int n);
int safe_multiplication(unsigned long long a, unsigned long long b, unsigned long long *result);

int main(void)
{
    const int N = 10;
    long double cosine_approx, sine_approx;

    //approximate cosine and sine and display (x=pi)
    cosine_approx = cosine(N, M_PI);
    sine_approx = sine(N, M_PI);
    printf("For n: %d, radians: pi\n", N);
    printf("Mclaurin Expansion of cosine: %Lf\n", cosine_approx);
    printf("Mclaurin Expansion of sine: %Lf\n", sine_approx);

    //approximate cosine and sine and display (x=pi/6)
    cosine_approx = cosine(N, M_PI/6);
    sine_approx = sine(N, M_PI/6);
    printf("For n: %d, radians: pi/6\n", N);
    printf("Mclaurin Expansion of cosine: %Lf\n", cosine_approx);
    printf("Mclaurin Expansion of sine: %Lf\n", sine_approx);
    exit(0);
}

long double cosine(int N, double x)
{
    long double expansion = 0;
    for(int n = 0; n < N; n++)
        expansion += (pow(-1, n)*(pow(x, 2*n)))/factorial(2*n);

    return expansion;
}

long double sine(int N, double x)
{
    long double expansion = 0;
    for(int n = 0; n < N; n++)
        expansion += (pow(-1, n)*(pow(x, (2*n)+1)))/factorial((2*n)+1);

    return expansion;
}

long double factorial(int n)
{
    unsigned long long int result = 1;

    for (int i = 1; i <= n; i++)
    {
        if(!safe_multiplication(result, i, &result)){
            printf("\nError: overflow in unsigned long long int");
            exit(1);
        }
    }

    if (result <= LDBL_MAX) {
        return (long double)result; // within range
    } else {
        printf("\nError: overflow when converting to long double");
        exit(1);
    }
}

int safe_multiplication(unsigned long long a, unsigned long long b, unsigned long long *result) {
    if (a == 0 || b == 0) {
        // avoid divide by zero error
        *result = 0;
        return 1;
    }
    if (ULLONG_MAX / a < b) {
        // overflow case
        return 0;
    } else {
        *result = a * b;
        return 1;
    }
}