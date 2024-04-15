#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#define SIZE 256
#define UPPER 1025
#define N 128

void ShellSort(int a[]);                        //Used in Question 1
void QuickSort(int b[], int first, int last);   //Used in Question 1
int Partition(int b[], int first, int last);    //Used in Question 1
int extreme_points(int const ARRAY[]);          //Used in Question 3

void Question1(int a[], int b[]);
void Question2(int const A[], int const B[]);
void Question3();
void Question4();
void Question5();

int main()
{
    //unique seed value
    srand(time(NULL));

    //arrays used in question 1
    int a[SIZE];
    int b[SIZE*2];

    Question1(a, b);
    Question2(a, b);
    Question3();
    Question4();
    Question5();
}


void Question1(int a[], int b[])
{
    //Populate arrays with random numbers (0 - 1024)
    for (int i = 0; i < SIZE; i++)
        a[i] = rand() % UPPER;

    for (int i = 0; i < SIZE*2; i++)
        b[i] = rand() % UPPER;

    //Sorting functions
    ShellSort(a);
    QuickSort(b, 0, SIZE*2 - 1);

    //Output arrays A, B, in that order
    printf("[");
    for(int i = 0; i < SIZE - 1; i++)
    {
        printf("%i, ", a[i]);
    }
    printf("%i]\n", a[SIZE-1]);
    printf("[");
    for(int i = 0; i < SIZE*2 - 1; i++)
    {
        printf("%i, ", b[i]);
    }
    printf("%i]\n", b[SIZE*2-1]);
}

void Question2(int const A[], int const B[])
{
    int c[SIZE*3];

    //Populate array C with arrays A and B
    for(int i = 0; i < SIZE; i++)
        c[i] = A[i];
    for(int i = 0; i < SIZE*2; i++)
        c[i+SIZE] = B[i];

    //Output Array C
    printf("[");
    for(int i = 0; i < SIZE*3 - 1; i++)
    {
        printf("%i, ", c[i]);
    }
    printf("%i]\n", c[SIZE*3-1]);
}

void Question3()
{
    int arr[N];
    int ext_cnt;

    //Populate array, Duplicates allowed since not enforced otherwise
    for(int i = 0; i < N; i++)
        arr[i] = rand() % N;

    //Print array
    printf("[");
    for(int i = 0; i < N; i++)
    {
        printf("%i, ", arr[i]);
    }
    printf("%i]\n", arr[N-1]);

    //Extreme points
    ext_cnt = extreme_points(arr);

    //Print SORTED when no extreme points are found
    if(ext_cnt == 0)
        printf("SORTED\n");
    /*
     * An array has no extreme points if and only if it is sorted is false
     * since there exists a case where the array has no extreme points, and is not sorted:
     * [1, 5, 5, 1].
     * */

    /*
     * Although in the case where and an array is sorted [1,2,3,4,5] or inversely [5,4,3,2,1]
     * it does not contain any extreme points.
     * Thus, in the absence of extreme points and duplicates the array is sorted.
     * */
}

void Question4()
{
    //Initialize and Populate array
    int numbers[N];
    int number;
    bool match;

    //Populate arrays with random unique numbers (0 - 1024)
    for (int i = 0; i < N; i++)
    {
        do
        {
            match = false;
            number = rand() % UPPER;
            for(int j = 0; j < i; j++)
            {
                if(number == numbers[j])
                    match = true;
            }
        }while(match);

        numbers[i] = number;
    }


    //assuming ((a,b),(c,d)) is equal to all a,b,c,d configurations to avoid redundant 2-pairs
    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            for (int k = j + 1; k < N; k++) {
                for (int l = k + 1; l < N; l++) {
                    // Check if product of (number[i], number[j]) is equal to product of (number[k], number[l])
                    if (numbers[i] * numbers[j] == numbers[k] * numbers[l]) {
                        printf("((%d, %d), (%d, %d))\n", numbers[i], numbers[j], numbers[k], numbers[l]);
                    }
                }
            }
        }
    }
}

int extreme_points(int const ARRAY[])
{
    int count = 0;
    int ext_pts[N - 2];
    for(int i = 1; i < N-1; i++)
    {
        if(((ARRAY[i-1] < ARRAY[i]) && (ARRAY[i] > ARRAY[i+1])) || ((ARRAY[i - 1] > ARRAY[i]) && (ARRAY[i] < ARRAY[i + 1])))
        {
            ext_pts[count] = ARRAY[i];
            count++;
        }
    }

    //Print extreme points
    printf("[");
    for(int i = 0; i < count-2; i++)
    {
        printf("%i, ", ext_pts[i]);
    }
    printf("%i]\n", ext_pts[count-1]);

    return count;
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


