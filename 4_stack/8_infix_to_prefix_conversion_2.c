//  !Write a program to convert an infix infixression to a prefix infixression.
/*
 ? For example, given an infix infixression (A – B/ C) * (A / K – L)

? Step 1: Reverse the infix string. Note that while reversing the string you must interchange left and right parentheses. (L – K / A) * (C / B – A)

Step 2: Obtain the corresponding postfix
infixression of the infix infixression obtained as
a result of Step 1.
The infixression is: (L – K / A) * (C / B – A)
Therefore, [L – (K A /)] * [(C B /) – A]
= [LKA/–] * [CB/A–]
= L K A / – C B / A – *


Step 3: Reverse the postfix infixression to get the
prefix infixression
Therefore, the prefix infixression is * – A / B
C – /A K L
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node
{
    char data;
    struct Node *next;
};
struct Node *top = NULL;
int len = 0;

void push(char ch)
{
    struct Node *new_node;
    new_node = (struct Node *)malloc(sizeof(struct Node));

    if (new_node == NULL)
    {
        printf("\nStack is Full");
    }
    else
    {
        new_node->data = ch;
        new_node->next = top;
        top = new_node;
        len++;
    }
}

char pop()
{
    char ch = -1;
    if (top == NULL)
    {
        printf("\nStack is Empty");
    }
    else
    {
        ch = top->data;
        top = top->next;
        len--;
    }
    return ch;
}

void Display()
{
    struct Node *ptr = top;
    printf("\nStack is : ");
    while (ptr != NULL)
    {
        printf("\t%c", ptr->data);
        ptr = ptr->next;
    }
}

char *reverse(char *infix)
{
    int i = 0, j = 0, len1;
    len1 = strlen(infix);
    j = len1 - 1;
    char *reversed = (char *)malloc((len1 + 2) * sizeof(char));

    while (j >= 0)
    {
        if (infix[i] == '(')
        {
            reversed[i] = ')';
        }
        else if (infix[i] == ')')
        {
            reversed[i] = '(';
        }
        else
        {
            reversed[i] = infix[j];
        }
        i++;
        j--;
    }
    reversed[i] = '\0';

    return reversed;
}

int pre(char ch)
{
    if (ch == '+' || ch == '-')
    {
        return 1;
    }
    else if (ch == '*' || ch == '/' || ch == '%')
    {
        return 2;
    }
    else
    {
        return 0;
    }
}

int isOperand(char ch)
{
    if (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '%')
    {
        return 0;
    }
    else
    {
        return 1;
    }
}

char *InToPost(char *infix)
{
    int i = 0, j = 0;
    char *postfix;
    int len1 = strlen(infix);
    postfix = (char *)malloc((len1 + 2) * sizeof(char));

    while (infix[i] != '\0')
    {
        if (isOperand(infix[i]))
        {
            postfix[j++] = infix[i++];
        }
        else
        {
            if (pre(infix[i]) > pre(top->data))
                push(infix[i++]);
            else
            {
                postfix[j++] = pop();
            }
        }
    }
    while (top != NULL)
    {
        postfix[j++] = pop();
    }

    postfix[j] = '\0';

    return postfix;
}

int main()
{
    char *infix, *postfix, *prefix;

    push('#');
    printf("\nEnter Infix infixression : ");
    gets(infix);

    printf("\nInfix infixression is : %s", infix);

    // reverse of infix
    infix = reverse(infix);
    printf("\nReverse of infix is : %s", infix);

    // postfix of reversed infix
    postfix = InToPost(infix);
    printf("\nPostfix infixression is : %s", postfix);

    // reverse of postfix i.e is infix
    prefix = reverse(postfix);

    printf("\nPrefix infixression is %s", prefix);
    return 0;
}