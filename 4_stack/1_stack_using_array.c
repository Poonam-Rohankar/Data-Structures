//  * Write a program to perform Push, Pop, and Peek operations on a stack.

#include <stdio.h>
#include <stdlib.h>

#define MAX 10 // size of array

int stk[MAX], top = -1; // top pointer always pointing on last element of stack

void push(int stk[], int value); // push element into stack

int pop(int stk[]); // pop element from top of stack

int peek(int stk[]); // get element that is on top of the stack

void display(int stk[]); // display all elements present in stack

//  ! --------MAIN -------------
int main()
{
    int choice, value;

    do
    {
        printf("\n *****MAIN MENU*****");
        printf("\n 1. PUSH");
        printf("\n 2. POP");
        printf("\n 3. PEEK");
        printf("\n 4. DISPLAY");
        printf("\n 5. EXIT");

        //  ?-----------
        printf("\nEnter Your Choice : ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
        {
            printf("\nEnter value to be pushed on stack : ");
            scanf("%d", &value);
            push(stk, value);
            break;
        }
        case 2:
        {
            value = pop(stk);

            if (value != -1)
            {
                printf("\nThe value popped from stack is : %d", value);
            }
            break;
        }
        case 3:
        {
            value = peek(stk);
            if (value != -1)
            {
                printf("\nThe value on top of the stack is : %d", value);
            }
            break;
        }
        case 4:
        {
            display(stk);
            break;
        }
        }
    } while (choice != 5);

    return 0;
}

void push(int stk[], int value)
{
    if (top == MAX - 1)
    {
        printf("\nSTACK OVRFLOW !");
    }
    else
    {
        top++; // increase top by 1
        stk[top] = value;
    }
}

int pop(int stk[])
{
    int value;
    if (top == -1)
    {
        printf("\nSTACK UNDERFLOW !");
        return -1;
    }
    else
    {
        value = stk[top];
        top--; // decrease top by 1
        return value;
    }
}

int peek(int stk[])
{
    if (top == -1)
    {
        printf("\nSTACK UNDERFLOW !");
        return -1;
    }
    else
    {
        return stk[top];
    }
}

void display(int stk[])
{
    int i;
    printf("\nStack is :\n");
    for (i = top; i >= 0; i--)
    {
        printf("\t| %d |", stk[i]);
        printf("\n\t ___ \n");
    }
}