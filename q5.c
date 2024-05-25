#include <stdlib.h>
#include <stdio.h>

void push(int stk[], int stack_ptr, int operand);
int pop(int stk[], int stack_ptr);

int main(void)
{
    const int N = 128;

    char characters[N];
    int stack[N];

    int number, operand_1, operand_2, div; //div - holds result of division operator
    int SP = -1, i = 0;        //Stack pointer initialized, Iterator for input string

    printf("Enter equation in postfix notation: ");
    scanf("%s", characters);

    while(characters[i] != 0)
    {
        switch (characters[i])
        {
            case 48 ... 57: //digit cases
                number = (int) characters[i] - 48;
                SP++;
                push(stack, SP, number);
                break;
            case 43: // "+" case
                operand_1 = pop(stack, SP);
                SP--;
                operand_2 = pop(stack, SP);
                push(stack, SP, operand_2 + operand_1);
                break;
            case 45: // "-" case
                operand_1 = pop(stack, SP);
                SP--;
                operand_2 = pop(stack, SP);
                push(stack, SP, operand_2 - operand_1);
                break;
            case 47: // "/" case
                operand_1 = pop(stack, SP);
                SP--;
                operand_2 = pop(stack, SP);
                if(operand_1 == 0) //divide by zero error
                {
                    printf("Error: Dividing by zero");
                    exit(1);
                }
                div = operand_2/operand_1;
                push(stack, SP, div);
                break;
            case 120: // "x" case
                operand_1 = pop(stack, SP);
                SP--;
                operand_2 = pop(stack, SP);
                push(stack, SP, operand_2 * operand_1);
                break;
            default: // invalid char case
                printf("Invalid character use, allowed - [0-9], [+,-,x,/]\n");
                exit(1);
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
    int popped_val = stk[stack_ptr];
    stk[stack_ptr] = 0;
    stack_ptr--;

    if(stack_ptr < -1)//print if invalid expression
    {
        printf("Invalid Postfix Sequence");
        exit(-1);
    }
    if(stack_ptr == -1)//print Empty Stack
    {
        printf("EMPTY\n");
        return popped_val;
    }
    for(int i = 0; i <= stack_ptr; i++)//print stack
        printf("%d, ", stk[i]);
    printf("\n");
    return popped_val;
}