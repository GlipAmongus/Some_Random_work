#include <stdlib.h>
#include <stdio.h>
#include <time.h>

unsigned long long cosine(int i);
unsigned long long sine(int i);

int main(void)
{
    //unique seed value
    srand(time(NULL));

    int n = (rand() % 32) + 1;

    long double cosine_approx = cosine(n);
    long double sine_approx = sine(n);

    printf("For n = %d\n", n);
    printf("Mclaurin Expansion of cosine: %Lf\n", cosine_approx);
    printf("Mclaurin Expansion of sine: %Lf\n", sine_approx);

    exit(0);
}

long double cosine(int i)
{
    for(int i)
}

long double sine(int i)
{

}
