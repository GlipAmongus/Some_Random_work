#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

long double newtonRaphson(long double xn_minus_1, long double n);
char cliValidation(void);
long double longd_validation(void);

int main(void)
{
    char cli;           //User iterated Newton Raphson

    long double n; // n - number to find square root of
    long double x; // x - initial guess
    int i = 0; // i - number of iterations

    printf("'q' - quit or 'SPACE' - iterate\n");
    printf("\nInput number to find square root of: ");
    n = longd_validation();
    printf("\nInitial Guess: ");
    x = longd_validation();

    do
    {
        x = newtonRaphson(x, n);

        printf("Iteration %d: %Lf", i, x);

        i++;
        cli = cliValidation();
    } while(cli != 'q');

    exit(0);
}

long double newtonRaphson(long double xn_minus_1, long double n)
{
    long double xn;

    long double f_x = (xn_minus_1)*(xn_minus_1) - n;
    long double f_x_prime = 2*xn_minus_1;

    if(f_x_prime == 0)
    {
        printf("Denominator is 0");
        return xn_minus_1;
    }

    xn = xn_minus_1 - (f_x / f_x_prime);

    return xn;
}

long double longd_validation(void)
{
    long double input;
    char buffer[128];
    int len;
    int decimal_count;

    bool validation;

    do
    {
        validation = true;
        decimal_count = 0;

        fgets(buffer, sizeof(buffer), stdin);
        len = strlen(buffer);

        while(len > 0 && isspace(buffer[len - 1]))
        {
            len --;
        }
        if(len > 0)
        {
            validation = true;

            for (int i = 0; i < len; i++)
            {
                if(buffer[i] == '.')
                    decimal_count++;

                if((!isdigit(buffer[i])) && buffer[i] != '.' || decimal_count > 1)
                {
                    printf("Error: Invalid type. Long Double expected:");
                    validation = false;
                    break;
                }
            }
        }

        // When valid convert back to long double
        if(validation)
            input = atof(buffer);

    }while(!validation);

    return input;
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
