// ! Write a program to implement queue using array

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
    struct Node *temp;

    if (front == NULL)
    {
        printf("\nQueue is Empty !");
    }
    else
    {
        x = front->data;
        temp = front; // node to be removed
        front = front->next;
        free(temp);
    }

    return x;
}

void display()
{
    struct Node *ptr = front;
    printf("\nQueue is : ");

    while (ptr != NULL)
    {
        printf("\t%d", ptr->data);
        ptr = ptr->next;
    }
}

int main()
{
    enqueue(12);
    enqueue(14);
    enqueue(11);
    enqueue(165);
    enqueue(132);

    display();

    printf("\nDequeued :\t%d", dequeue());

    display();
    return 0;
}