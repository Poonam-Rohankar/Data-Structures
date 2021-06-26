// * Write a program to implement a linked stack.

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    struct Node *prev;
    int data;
};

struct Node *top = NULL; // top pointer

struct Node *push(struct Node *, int); // push element on top of stack

struct Node *pop(struct Node *); // pop element from top of stack

struct Node *peek(struct Node *); // print top element

struct Node *display(struct Node *);

//  !---------- MAIN ----------------

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

        // ?-----------

        printf("\nEnter Your Choice : ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
        {
            printf("\n Enter the number to be pushed on stack: ");
            scanf("%d", &value);
            top = push(top, value);
            break;
        }
        case 2:
        {
            top = pop(top);
            break;
        }
        case 3:
        {
            top = peek(top);
            break;
        }
        case 4:
        {
            top = display(top);
        }
        }
    } while (choice != 5);

    return 0;
}

struct Node *push(struct Node *top, int value)
{
    struct Node *new_node;
    new_node = (struct Node *)malloc(sizeof(struct Node));
    new_node->data = value;
    new_node->prev = NULL;

    if (top == NULL)
    {
        top = new_node;
    }
    else
    {
        new_node->prev = top;
        top = new_node;
    }

    return top;
}

struct Node *pop(struct Node *top)
{
    struct Node *temp = top;

    if (top == NULL)
    {
        printf("\n STACK UNDERFLOW");
    }
    else
    {
        top = top->prev;
        printf("\nThe value being deleted is: %d", temp->data);
        free(temp);
    }
    return top;
}

struct Node *peek(struct Node *top)
{
    if (top == NULL)
    {
        printf("\n STACK UNDERFLOW");
    }
    else
    {
        printf("\nThe value at the top of stack is: %d", top->data);
    }

    return top;
}

struct Node *display(struct Node *top)
{
    struct Node *ptr = top;

    printf("\nStack is :\n");
    while (ptr != NULL)
    {
        printf("\t| %d |", ptr->data);
        printf("\n\t ___ \n");
        ptr = ptr->prev;
    }

    return top;
}