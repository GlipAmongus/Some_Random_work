#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <stdbool.h>

void shellSort(int a[], size_t capacity);
void quickSort(int b[], int first, int last);
int partition(int b[], int first, int last);

int main(void) {
    const int N = 256;
    const int UPPER = 1025;

    //arrays used in question 1
    int array_a[N];
    int array_b[N*2];

    //array used in question 2, size of array c calculated using size of array a + b
    size_t a_size = sizeof(array_a)/sizeof(array_a[0]);
    size_t b_size = sizeof(array_b)/sizeof(array_b[0]);
    size_t c_size = a_size + b_size;
    int array_c[c_size];

    //unique seed value
    srand(time(NULL));

    //Populate arrays with random numbers (0 - 1024)
    for (int i = 0; i < a_size; i++)
        array_a[i] = rand() % UPPER;

    for (int i = 0; i < b_size; i++)
        array_b[i] = rand() % UPPER;

    //Sorting functions
    shellSort(array_a, a_size);
    quickSort(array_b, 0, (int)(b_size-1));

    //Output arrays A, B, in that order
    printf("ARRAY A:\n");
    for(int i = 0; i < a_size; i++)
        printf("%d, ", array_a[i]);

    printf("\n\nARRAY B:\n");
    for(int i = 0; i < b_size; i++)
        printf("%d, ", array_b[i]);

    //Populate array C with arrays A and B in linear time
    for(int i = 0; i < a_size; i++)
        array_c[i] = array_a[i];
    for(int i = 0; i < b_size; i++)
        array_c[i+b_size] = array_b[i];

    //Output Array C
    printf("\n\nARRAY C:\n");
    for(int i = 0; i < c_size; i++)
        printf("%d, ", array_c[i]);

    exit(0);
}

void shellSort(int a[], size_t capacity)
{
    int gap = (int) (capacity / 2);
    bool flag = true;
    int temp;

    do
    {
        flag = false;

        for (int i = 0; i < capacity - gap; i++)
        {
            if(a[i] > a[i+gap])
            {
                temp = a[i];
                a[i] = a[i + gap];
                a[i + gap] = temp;
                flag = true;
            }
        }

        if(gap > 1)
            gap = (int) (gap / 2);
    }while(gap >= 1 && flag == true);
}

void quickSort(int b[], int first, int last)
{
    int pivot_point;

    if(first < last)
    {
        pivot_point = partition(b, first, last);
    }
    else
    {
        return;
    }
    quickSort(b, first, pivot_point - 1);
    quickSort(b, pivot_point + 1, last);
}

int partition(int b[], int first, int last)
{
    int temp;
    int left = first;
    int right = last;
    int pivot = b[first];

    do
    {
        while((b[left] <= pivot) && (left != last))
            left++;
        while((b[right] > pivot) && (right != first))
            right--;

        if(left < right)
        {
            temp = b[left];
            b[left] = b[right];
            b[right] = temp;
        }

    }while(left < right);

    temp = b[first];
    b[first] = b[right];
    b[right] = temp;

    return right;
}