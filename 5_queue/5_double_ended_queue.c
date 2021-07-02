// ! Write a program to implement double ended queue

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *prev;
    struct Node *next;
} *front = NULL, *rear = NULL;

void enqueue_front(int x)
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
        new_node->prev = NULL;

        if (front == NULL)
        {
            front = rear = new_node;
        }
        else
        {
            new_node->next = front;
            front->prev = new_node;
            front = new_node;
        }
    }
}

void enqueue_rear(int x)
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
        new_node->prev = NULL;

        if (front == NULL)
        {
            front = rear = new_node;
        }
        else
        {
            rear->next = new_node;
            new_node->prev = rear;
            rear = new_node;
        }
    }
}

int dequeue_front()
{
    int x;

    if (front == NULL)
    {
        printf("\nStack is Empty !");
    }
    else
    {
        x = front->data;
        struct Node *temp = front;
        front->prev = NULL;
        front = front->next;

        free(temp);
    }

    return x;
}

int dequeue_rear()
{
    int x;

    if (front == NULL)
    {
        printf("\nStack is Empty !");
    }
    else
    {
        x = rear->data;
        struct Node *temp = rear;
        rear = rear->prev;
        rear->next = NULL;

        free(temp);
    }

    return x;
}

void Display()
{
    struct Node *ptr = front;

    printf("\nQueue is :");
    while (ptr != NULL)
    {
        printf("\t%d", ptr->data);
        ptr = ptr->next;
    }
}

int main()
{
    enqueue_front(2);
    enqueue_front(1);
    enqueue_rear(3);
    enqueue_rear(4);
    Display();

    dequeue_front();
    Display();

    dequeue_rear();
    Display();

    return 0;
}