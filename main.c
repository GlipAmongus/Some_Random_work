#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#define SIZE 256
#define MAX 1025

void ShellSort(int A[]);
void QuickSort(int B[], int first, int last);
int Partition(int B[], int first, int last);

void Question1(int A[], int B[]);

int main()
{
        //unique seed value
        srand(time(NULL));

        //arrays used in question 1
        int A[SIZE];
        int B[SIZE*2];

        //array used in question 2
        int C[SIZE*3];

        Question1(A, B);
        printf("[");
        for(int i = 0; i < SIZE; i++)
        {
            printf("%i , ", A[i]);
        }
        printf("]");
        printf("[");
        for(int i = 0; i < SIZE*2; i++)
        {
            printf("%i , ", B[i]);
        }
        printf("]");


}

void Question1(int A[], int B[])
{
    //Populate arrays with random numbers (0 + 1024)
    for (int i = 0; i < SIZE; i++)
        A[i] = rand() % MAX;

    for (int i = 0; i < SIZE*2; i++)
        B[i] = rand() % MAX;

    ShellSort(A);

    QuickSort(B, 0, SIZE * 2 - 1);
}

void ShellSort(int A[])
{
    int gap = (int) SIZE / 2;
    bool flag = true;
    int temp;

    do
    {
        flag = false;

        for (int i = 0; i < SIZE - gap; i++)
        {
            if(A[i] > A[i+gap])
            {
                temp = A[i];
                A[i] = A[i + gap];
                A[i + gap] = temp;
                flag = true;
            }
        }

        if(gap > 1)
            gap = (int) gap / 2;
    }while(gap >= 1 && flag == true);
}

void QuickSort(int B[], int first, int last)
{
    int pivot_point;

    if(first < last)
    {
        pivot_point = Partition(B, first, last);
    }
    else
    {
        return;
    }
    QuickSort(B, first, pivot_point - 1);
    QuickSort(B, pivot_point + 1, last);
}

int Partition(int B[], int first, int last)
{
    int temp;
    int left = first;
    int right = last;
    int pivot = B[first];

    do
    {
        while((B[left] <= pivot) && (left != last))
            left++;
        while((B[right] > pivot) && (right != first))
            right--;

        if(left < right)
        {
            temp = B[left];
            B[left] = B[right];
            B[right] = temp;
        }

    }while(left < right);

    temp = B[first];
    B[first] = B[right];
    B[right] = temp;

    return right;
}


