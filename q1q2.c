#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <stdbool.h>

void shellSort(int a[], size_t capacity);
void quickSort(int b[], int first, int last);
int partition(int b[], int first, int last);
void array_merge(const int arr_a[], const int arr_b[], int arr_c[], size_t a_len, size_t b_len);

int main(void) {
    const int N = 256, UPPER = 1025;

    //arrays used in question 1
    int array_a[N], array_b[N*2];

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

    //Output unsorted arrays A, B, in that order
    printf("ARRAY A Unsorted:\n");
    for(int i = 0; i < a_size; i++)
        printf("%d, ", array_a[i]);

    printf("\n\nARRAY B Unsorted:\n");
    for(int i = 0; i < b_size; i++)
        printf("%d, ", array_b[i]);

    //Sorting functions
    shellSort(array_a, a_size);
    quickSort(array_b, 0, (int)(b_size-1));

    //Output arrays A, B, in that order
    printf("\n\nARRAY A Sorted:\n");
    for(int i = 0; i < a_size; i++)
        printf("%d, ", array_a[i]);

    printf("\n\nARRAY B Sorted:\n");
    for(int i = 0; i < b_size; i++)
        printf("%d, ", array_b[i]);

    array_merge(array_a, array_b, array_c, a_size, b_size);

    //Output Array C
    printf("\n\nARRAY C Sorted:\n");
    for(int i = 0; i < c_size; i++)
        printf("%d, ", array_c[i]);

    exit(0);
}

void shellSort(int a[], size_t capacity)
{
    int gap = (int) (capacity / 2);
    bool flag;
    int temp;

    do
    {
        flag = false;
        for (int i = 0; i < capacity - gap; i++) //Iterate until gap reaches last position
        {
            if(a[i] > a[i+gap]) //If greater then swap
            {
                temp = a[i];
                a[i] = a[i + gap];
                a[i + gap] = temp;
                flag = true;
            }
        }

        if(gap > 1) //Half gap after each iteration
            gap = (int) (gap / 2);
    }while(flag == true); //Loop until flag is not activated
}

void quickSort(int b[], int first, int last)
{
    int pivot_point;

    if(first < last) //Check if base case
        pivot_point = partition(b, first, last);
    else
        return;

    //Recursive call left side
    quickSort(b, first, pivot_point - 1);
    //Recursive call right side
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
        //Increment left until value at position 'left' is larger than or equal to pivot or is the final position
        while((b[left] <= pivot) && (left != last))
            left++;
        //Decrement right until value at position 'right' is smaller than the pivot or is the first position
        while((b[right] > pivot) && (right != first))
            right--;

        //Swap values at positions 'left' and 'right' when left is smaller than right
        if(left < right)
        {
            temp = b[left];
            b[left] = b[right];
            b[right] = temp;
        }

    }while(left < right); //Loop until left is larger than or equal to right

    //Swap positions 'first' and 'right'
    temp = b[first];
    b[first] = b[right];
    b[right] = temp;

    return right; //Return right as the pivot point
}

void array_merge(const int arr_a[], const int arr_b[], int arr_c[], size_t a_len, size_t b_len)
{
    int counter_a = 0, counter_b = 0, counter_c = 0; //Array iterators to merge Arrays to Array C

    //Merge array C with arrays A and B in linear time
    while(counter_a < a_len && counter_b < b_len)
    {
        //Concatenate values in ascending order
        if(arr_a[counter_a] <= arr_b[counter_b])
        {
            arr_c[counter_c] = arr_a[counter_a];
            counter_a++;
        }
        else
        {
            arr_c[counter_c] = arr_b[counter_b];
            counter_b++;
        }
        counter_c++;
    }
    //Concatenate the remaining values in the arrays
    while(counter_a < a_len)
    {
        arr_c[counter_c] = arr_a[counter_a];
        counter_a++, counter_c++;
    }
    while(counter_b < b_len)
    {
        arr_c[counter_c] = arr_b[counter_b];
        counter_b++, counter_c++;
    }
}