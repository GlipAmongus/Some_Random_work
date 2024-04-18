#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

int main(void)
{
    const int N = 256;
    const int UPPER = 1024;

    int array_n[N];
    int number;     //temp. random number generated
    bool match;     //unique constraint

    //Populate arrays with random unique numbers (1 - 1024)
    for (int i = 0; i < N; i++)
    {
        do
        {
            match = false;
            number = (rand() % UPPER) + 1;
            for(int j = 0; j < i; j++)
            {
                if(number == array_n[j])
                    match = true;
            }
        }while(match);

        array_n[i] = number;
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = i + 1; j < N; j++)
        {
            for (int k = j + 1; k < N; k++)
            {
                for (int l = k + 1; l < N; l++)
                {
                    // Check if product of (number[i], number[j]) is equal to product of (number[k], number[l])
                    if (array_n[i] * array_n[j] == array_n[k] * array_n[l])
                        printf("((%d, %d), (%d, %d))\n", array_n[i], array_n[j], array_n[k], array_n[l]);
                }
            }
        }
    }

    exit(0);
}