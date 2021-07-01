//  !Write a program to convert an infix expression to a prefix expression.
/*
 ? For example, given an infix expression (A – B/ C) * (A / K – L)

? Step 1: Reverse the infix string. Note that while reversing the string you must interchange left and right parentheses. (L – K / A) * (C / B – A)

Step 2: Obtain the corresponding postfix
expression of the infix expression obtained as
a result of Step 1.
The expression is: (L – K / A) * (C / B – A)
Therefore, [L – (K A /)] * [(C B /) – A]
= [LKA/–] * [CB/A–]
= L K A / – C B / A – *


Step 3: Reverse the postfix expression to get the
prefix expression
Therefore, the prefix expression is * – A / B
C – /A K L
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// *---------
#define MAX 100
char stk[MAX];
int top = -1;
// *---------

void push(char stk[], char);
char pop(char stk[]);
void reverse(char exp[]);
int precedence(char);
void infix_postfix(char infix[], char postfix[]);

// ? ---
char temp[MAX];
// ---
int main()
{
    char infix[MAX], postfix[MAX];

    printf("\nEnter infix expression : ");
    gets(infix);

    // ! reverse of infix
    reverse(infix);

    strcpy(postfix, "");

    // ! calculate postfix
    infix_postfix(temp, postfix);
    printf("\nThe corrosponding postfix expression is : ");
    puts(postfix);

    strcpy(temp, "");
    
    // ! reverse postfix i.e prefix
    reverse(postfix);

    printf("\nThe corrosponding prefix expression is : ");
    puts(temp);

    return 0;
}

void push(char stk[], char ch)
{
    if (top == MAX - 1)
    {
        printf("\nStack is Full");
    }
    else
    {
        top++;
        stk[top] = ch;
    }
}

char pop(char stk[])
{
    char ch = -1;

    if (top == -1)
    {
        printf("\nStack is Empty");
    }
    else
    {
        ch = stk[top];
        top--;
    }
    return ch;
}

void reverse(char exp[])
{
    int i = 0, j = 0, len;
    len = strlen(exp);
    j = len - 1;

    while (j >= 0)
    {
        if (exp[i] == '(')
        {
            temp[i] = ')';
        }
        else if (exp[i] == ')')
        {
            temp[i] = '(';
        }
        else
        {
            temp[i] = exp[j];
        }
        i++;
        j--;
    }
}

int precedence(char ch)
{
    if (ch == '*' || ch == '/' || ch == '%')
    {
        return 2;
    }
    else if (ch == '+' || ch == '-')
    {
        return 1;
    }
}

void infix_postfix(char infix[], char postfix[])
{
    int i = 0, j = 0;
    char tmp;
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
            tmp = pop(stk); // remove left paranthesis
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
            while ((top != -1) && (stk[top] != '(') && (precedence(stk[top]) > precedence(infix[i])))
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
            exit(1);
        }
    }

    while ((top != -1) && (stk[top] != '('))
    {
        postfix[j] = pop(stk);
        j++;
    }
    postfix[j] = '\0';
}
