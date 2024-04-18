#include <stdio.h>
#include <stdlib.h>
#include <time.h>

long double newtonRaphson(long double xn_minus_1, int n);
char cliValidation(void);

int main(void)
{
    const int N = 1024;

    //unique seed value
    srand(time(NULL));

    char cli;           //User iterated Newton Raphson

    int n = (rand() % N)+1;
    long double x = (rand() % N)+1;

    printf("'q' - quit or 'SPACE' - iterate\n");
    printf("\nApproximation of: (%d)^1/2\n", n);
    printf("Initial Guess: %Lf\n", x);

    do
    {
        x = newtonRaphson(x, n);

        printf("Newton Raphson: %Lf\n", x);

        cli = cliValidation();
    } while(cli != 'q');

    exit(0);
}

long double newtonRaphson(long double xn_minus_1, int n)
{
    long double xn;

    long double f_x = (xn_minus_1)*(xn_minus_1) + n;
    long double f_x_prime = 2*xn_minus_1;

    if(f_x_prime == 0)
    {
        printf("Denominator is 0");
        return xn_minus_1;
    }

    xn = xn_minus_1 - (f_x / f_x_prime);

    return xn;
}

char cliValidation(void)
{
    char ch;

    ch = getchar();
    while(ch != '\n' && ch != 'q')
    {
        //empty buffer
        while((ch = getchar()) != '\n')
        {
            putchar(ch);
        }

        printf("Error: Invalid character. 'q' or 'ENTER' accepted\n");
    }

    return ch;
}
