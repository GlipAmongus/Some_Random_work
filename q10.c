#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int max(int arr[], int n);

int main(void)
{
    const int N = 32;

    //unique seed value
    srand(time(NULL));

    int array_n[N];

    printf("Array of numbers:\n");
    for(int i = 0; i < N; i++)
    {
        array_n[i] = rand() % N + 1;
        printf("%d, ", array_n[i]);
    }
    printf("\nLargest number: %d", max(array_n, N-1));

    exit(0);
}

int max(int arr[], int n)
{
    int temp;
    if(n == 1) //base case
        return arr[0];
    if(arr[n] > (temp = max(arr, n-1))) //recursive call with array size -1
    {
        return arr[n]; //larger number found
    }else{
        return temp;
    }
}