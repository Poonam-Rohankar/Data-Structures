//  ! Write a program to convert an infix expression into its equivalent postfix notation.

#
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX 100
char stk[MAX];
int top = -1;

void push(char stk[], char);
char pop(char stk[]);

int priority(char);
void infix_postfix(char infix[], char postfix[]);

int main()
{
    char infix[MAX], postfix[MAX];

    printf("\nEnter Infix Expression : ");
    gets(infix);

    strcpy(postfix, "");

    infix_postfix(infix, postfix);

    printf("\nPostfix Expression is : ");
    puts(postfix);

    return 0;
}

void push(char stk[], char x)
{
    if (top == MAX - 1)
    {
        printf("\nStack is full !");
    }
    else
    {
        top++;
        stk[top] = x;
    }
}

char pop(char stk[])
{
    char x = ' ';

    if (top == -1)
    {
        printf("\nStack is Empty");
    }
    else
    {
        x = stk[top];
        top--;
    }
    return x;
}

int priority(char x)
{
    if (x == '/' || x == '*' || x == '%')
        return 1;
    else if (x == '+' || x == '-')
        return 0;
}

void infix_postfix(char infix[], char postfix[])
{
    int i = 0, j = 0;
    char temp;
    strcpy(postfix, "");

    while (infix[i] != '\0')
    {
        if (infix[i] == '(')
        {
            push(stk, infix[i]);
            i++;
        }
        else if (infix[i] == ')')
        {
            while ((top != -1) && (stk[top] != '('))
            {
                postfix[j] = pop(stk);
                j++;
            }
            if (top == -1)
            {
                printf("\n INCORRECT EXPRESSION");
                exit(0);
            }

            temp = pop(stk); //remove left parenthesis
            i++;
        }
        else if (isdigit(infix[i]) || isalpha(infix[i]))
        {
            postfix[j] = infix[i];
            j++;
            i++;
        }

        else if (infix[i] == '+' || infix[i] == '-' || infix[i] == '*' || infix[i] == '/' || infix[i] == '%')
        {
            while ((top != -1) && (stk[top] != '(') && (priority(stk[top]) > priority(infix[i])))
            {
                postfix[j] = pop(stk);
                j++;
            }
            push(stk, infix[i]);
            i++;
        }
        else
        {
            printf("\n INCORRECT ELEMENT IN EXPRESSION");
            exit(0);
        }
    }

    while ((top != -1) && (stk[top] != '('))
    {
        postfix[j] = pop(stk);
        j++;
    }
    postfix[j] = '\0';
}