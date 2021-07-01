// ! Write a program to evaluate a postfix expression.

#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX 100
float stk[MAX];
int top = -1;

// TODO ---------
void push(float stk[], float x);
float pop(float stk[]);
float evaluate_postfix(char exp[]);

// * -------------Main
int main()
{
    float result;
    char exp[MAX];

    printf("\nEnter Postfix Expression : ");
    gets(exp);

    result = evaluate_postfix(exp);

    printf("\nValue of postfix expression after evaluation : %.2f", result);

    return 0;
}

// *-----------------------
void push(float stk[], float x)
{
    if (top == MAX - 1)
    {
        printf("\nStack is Full !");
    }
    else
    {
        top++;
        stk[top] = x;
    }
}

float pop(float stk[])
{
    float x = -1;
    if (top == -1)
    {
        printf("\nStack is Empty !");
    }
    else
    {
        x = stk[top];
        top--;
    }

    return x;
}

float evaluate_postfix(char exp[])
{
    int i = 0;
    float operand1, operand2, result;

    while (exp[i] != '\0')
    {
        if (isdigit(exp[i]))
        {
            push(stk, (float)(exp[i] - '0')); // push operands into stack
        }
        else
        {
            operand2 = pop(stk);
            operand1 = pop(stk);

            switch (exp[i])
            {
            case '+':
            {
                result = operand1 + operand2;
                break;
            }
            case '-':
            {
                result = operand1 - operand2;
                break;
            }
            case '*':
            {
                result = operand1 * operand2;
                break;
            }
            case '/':
            {
                result = operand1 / operand2;
                break;
            }
            case '%':
            {
                result = (int)operand1 % (int)operand2;
                break;
            }
            }

            push(stk, result); // push result into stack for futher calculations

        }
        i++;
    }

    return (pop(stk)); // final result
}