#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <string.h>

#define SIZE 256
#define UPPER 1025
#define N 128

void ShellSort(int a[]);                            //Used in Question 1
void QuickSort(int b[], int first, int last);       //Used in Question 1
int Partition(int b[], int first, int last);        //Used in Question 1
int extreme_points(int const ARRAY[]);              //Used in Question 3
void push(int stk[], int stack_ptr, int operand);   //Used in Question 5
int pop(int stk[], int stack_ptr);                  //Used in Question 5
bool prime_boolean(int n);                          //Used in Question 6
void seive_of_Eratosthene();                        //Used in Question 6

void Question1(int a[], int b[]);
void Question2(int const A[], int const B[]);
void Question3();
void Question4();
void Question5();
void Question6();

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
    Question6();
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
        printf("%d, ", a[i]);
    }
    printf("%d]\n", a[SIZE-1]);
    printf("[");
    for(int i = 0; i < SIZE*2 - 1; i++)
    {
        printf("%d, ", b[i]);
    }
    printf("%d]\n", b[SIZE*2-1]);
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
        printf("%d, ", c[i]);
    }
    printf("%d]\n", c[SIZE*3-1]);
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
        printf("%d, ", arr[i]);
    }
    printf("%d]\n", arr[N-1]);

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
     * Although in the case where an array is sorted [1,2,3,4,5] or inversely [5,4,3,2,1]
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

    for (int i = 0; i < N; i++)
    {
        for (int j = i + 1; j < N; j++)
        {
            for (int k = j + 1; k < N; k++)
            {
                for (int l = k + 1; l < N; l++)
                {
                    // Check if product of (number[i], number[j]) is equal to product of (number[k], number[l])
                    if (numbers[i] * numbers[j] == numbers[k] * numbers[l])
                        printf("((%d, %d), (%d, %d))\n", numbers[i], numbers[j], numbers[k], numbers[l]);
                }
            }
        }
    }
}

void Question5()
{
    char characters[N];
    int stack[N];
    int number, operand_1, operand_2;
    int SP = -1;
    int i = 0;

    printf("Enter equation in postfix notation: ");
    scanf("%s", characters);

    while(characters[i] != 0)
    {
        switch (characters[i])
        {
            case 48 ... 57:
                number = (int) characters[i] - 48;
                push(stack, SP, number);
                SP++;
                break;
            case 43:
                operand_1 = pop(stack, SP);
                SP--;
                operand_2 = pop(stack, SP);
                SP--;
                push(stack, SP, operand_2 + operand_1);
                SP++;
                break;
            case 45:
                operand_1 = pop(stack, SP);
                SP--;
                operand_2 = pop(stack, SP);
                SP--;
                push(stack, SP, operand_2 - operand_1);
                SP++;
                break;
            case 47:
                operand_1 = pop(stack, SP);
                SP--;
                operand_2 = pop(stack, SP);
                SP--;
                push(stack, SP, operand_2 / operand_1);
                SP++;
                break;
            case 120:
                operand_1 = pop(stack, SP);
                SP--;
                operand_2 = pop(stack, SP);
                SP--;
                push(stack, SP, operand_2 * operand_1);
                SP++;
                break;
        }
        i++;
    }
}

void Question6()
{
    for(int i = 1; i < SIZE; i++)
    {
        if(prime_boolean(i))
            printf("%d, ", i);
    }

    seive_of_Eratosthene();
}

void seive_of_Eratosthene()
{
    bool prime[SIZE];
    memset(prime, true, SIZE);

    for(int p = 2; p*p <= SIZE; p++)
    {
        if(prime[p]){
            //marking multiples of prime numbers
            for(int i = p*p; i <= SIZE; i += p)
            {
                /*
                 * check through multiples of p at p^2 or greater
                 * since multiples of p smaller than p^2 have already been checked
                 * */
                 prime[i] = false;
            }
        }
    }

    for(int p = 2; p < SIZE; p++)
    {
        if(prime[p])
            printf("%d, ",p);
    }
    //store prime multiples in array
    //iterate through
}

bool prime_boolean(int n)
{
    int i = 3;

    switch (n)
    {
        case 1:
            return false;
        case 2 ... 3:
            return true;
        default:
            if(n % 2 == 0)
                return false;
            while(i*i <= n)
            {
                if(n % i == 0)
                    return false;
                i = i+2;
            }
            return true;
    }
}

void push(int stk[], int stack_ptr, int operand)
{
    stack_ptr++;
    stk[stack_ptr] = operand;

    //Print Stack
    for(int i = 0; i <= stack_ptr; i++)
        printf("%d, ", stk[i]);
    printf("\n");
}

int pop(int stk[], int stack_ptr)
{
    int temp;
    temp = stk[stack_ptr];
    stk[stack_ptr] = 0;
    stack_ptr--;

    //Print Empty Stack
    if(stack_ptr < -1)
    {
        printf("Invalid Postfix Sequence");
        exit(-1);
    }
    if(stack_ptr == -1)
    {
        printf("EMPTY\n");
        return temp;
    }
    for(int i = 0; i <= stack_ptr; i++)
        printf("%d, ", stk[i]);
    printf("\n");
    return temp;
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
        printf("%d, ", ext_pts[i]);
    }
    printf("%d]\n", ext_pts[count-1]);

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


