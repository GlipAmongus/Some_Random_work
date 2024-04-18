#include <stdlib.h>
#include <stdio.h>

int main(void)
{
    int n;

    for(int i = 2; i <= 512; i++)
    {
        n = i;
        while(n != 1)
        {
            if(n % 2 == 0)
            {
                n /= 2;
            }
            else
            {
                n = (3 * n) + 1;
            }
        }
    }
    exit(0);
}