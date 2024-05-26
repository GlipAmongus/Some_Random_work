#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

long double newtonRaphson(long double xn_minus_1, long double n);
char cliValidation(void);

int main(void)
{
    char cli;           //User iterated Newton Raphson
    long double n = 3.5; // n - number to find square root of
    long double x = 100;  // x - initial guess
    int i = 0; // i - number of iterations

    printf("'q' - quit or 'ENTER' - iterate\n");
    printf("\nInput number to find square root of: %Lf", n);
    printf("\nInitial Guess: %Lf\n", x);

    do {
        x = newtonRaphson(x, n);
        printf("Iteration %d: %Lf", i, x);
        cli = cliValidation(); //ask user to continue or terminate
        i++;
    } while(cli != 'q');
    exit(0);
}

long double newtonRaphson(long double xn_minus_1, long double n)
{
    long double xn;
    //calculate f(x) = x^2 - n, f'(x) = 2x
    long double f_x = (xn_minus_1)*(xn_minus_1) - n;
    long double f_x_prime = 2*xn_minus_1;

    if(f_x_prime == 0) //divide by zero error
    {
        printf("Denominator is 0\n");
        exit(1);
    }

    //Newton Raphson method: xn = xn_minus_1 - f(x)/f'(x)
    xn = xn_minus_1 - (f_x / f_x_prime);
    return xn;
}

char cliValidation(void)
{
    char ch;
    bool valid;
    do {
        valid = true;
        ch = getchar();
        while (ch != '\n' && ch != 'q') //error case if 'q' or 'ENTER'
        {
            while ((ch = getchar()) != '\n')//empty buffer
                putchar(ch);
            printf("\nError: Invalid character. 'q' or 'ENTER' accepted\n");
            valid = false;
        }
    }while(!valid);
    return ch;
}