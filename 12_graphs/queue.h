#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
} *front = NULL, *rear = NULL;

void enqueue(int x)
{
    struct Node *new_node;
    new_node = (struct Node *)malloc(sizeof(struct Node));

    if (new_node == NULL)
    {
        printf("\nQueue is Full !");
    }
    else
    {
        new_node->data = x;
        new_node->next = NULL;

        if (front == NULL)
        {
            front = rear = new_node;
        }
        else
        {

            rear->next = new_node;
            rear = new_node;
        }
    }
}

int dequeue()
{
    int x = -1;

    if (front == NULL)
    {
        printf("\nQueue is Empty");
    }
    else
    {
        x = front->data;
        struct Node *temp = front;

        front = front->next;
        free(temp);
    }

    return x;
}

int isEmpty()
{
    return front == NULL;
}