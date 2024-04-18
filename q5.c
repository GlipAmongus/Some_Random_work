#include <stdlib.h>
#include <stdio.h>

int* dynamicInit(size_t capacity);
int* dynamicResize(int *d_array, size_t *capacity);
void push(int stk[], int stack_ptr, int operand);
int pop(int stk[], int stack_ptr);

int main(void)
{
    const int N = 128;
    size_t stack_N = 8;

    char characters[N];

    int number, operand_1, operand_2;
    int SP = -1;        //Stack pointer initialized
    int i = 0;          //loop through input string

    int *stack = dynamicInit(stack_N);

    printf("Enter equation in postfix notation: ");
    scanf("%s", characters);

    while(characters[i] != 0)
    {
        switch (characters[i])
        {
            case 48 ... 57:
                number = (int) characters[i] - 48;
                SP++;
                if(SP == stack_N)
                    stack = dynamicResize(stack, &stack_N);
                push(stack, SP, number);
                break;
            case 43:
                operand_1 = pop(stack, SP);
                SP--;
                operand_2 = pop(stack, SP);
                push(stack, SP, operand_2 + operand_1);
                break;
            case 45:
                operand_1 = pop(stack, SP);
                SP--;
                operand_2 = pop(stack, SP);
                push(stack, SP, operand_2 - operand_1);
                break;
            case 47:
                operand_1 = pop(stack, SP);
                SP--;
                operand_2 = pop(stack, SP);
                push(stack, SP, operand_2 / operand_1);
                break;
            case 120:
                operand_1 = pop(stack, SP);
                SP--;
                operand_2 = pop(stack, SP);
                push(stack, SP, operand_2 * operand_1);
                break;
        }
        i++;
    }

    exit(0);
}

void push(int stk[], int stack_ptr, int operand)
{
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

int* dynamicInit(size_t capacity)
{
    int *d_array = calloc(capacity, sizeof(int));
    if(d_array == NULL)
        return NULL;

    return d_array;
}

int* dynamicResize(int* d_array, size_t *capacity)
{
    *capacity = (*capacity) * 2;

    int *temp = d_array;

    d_array = (int *) realloc(d_array, *capacity);
    if (d_array == NULL)
        d_array = temp;

    return d_array;
}


