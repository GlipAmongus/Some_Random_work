#include <stdio.h>
#include <stdlib.h>

int max(int arr[], int n);

int main(void)
{
    const int N = 256;

    int array_n[N];
    for(int i = 0; i < N; i++)
    {
        array_n[i] = rand() % 1024 + 1;
    }
    printf("%d", max(array_n, N-1));

    exit(0);
}

int max(int arr[], int n)
{
    int temp;
    if(n == 1)
        return arr[0];
    if(arr[n] > (temp = max(arr, n-1)))
    {
        return arr[n];
    }else{
        return temp;
    }
}