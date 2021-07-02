// ! Write a program to implement circular queue using array

#include <stdio.h>
#include <stdlib.h>

struct Circular
{
    int size;
    int *Q;
    int front;
    int rear;
};

void enqueue(struct Circular *q, int);
int dequeue(struct Circular *q);
void display(struct Circular q);

int main()
{
    struct Circular q;

    printf("\nEnter size of queue : ");
    scanf("%d", &q.size);

    // ! create array of size
    q.Q = (int *)malloc(q.size * sizeof(int));

    q.front = q.rear = -1; // ! initially queue is empty

    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);
    enqueue(&q, 40);
    enqueue(&q, 50);
    enqueue(&q, 60);

    display(q);

    return 0;
}

void enqueue(struct Circular *q, int x)
{

    if ((q->rear + 1) % q->size == q->front)
    {
        printf("\nQueue is Full !");
    }
    else
    {
        q->rear = (q->rear + 1) % q->size;
        q->Q[q->rear] = x;
    }
}

int dequeue(struct Circular *q)
{
    int x;

    if (q->front == q->rear)
    {
        printf("\nQueue is Empty !");
    }
    else
    {
        q->front = (q->front + 1) % q->size;
        x = q->Q[q->front];
    }

    return x;
}

void display(struct Circular q)
{
    int i = q.front + 1;

    printf("\nQueue is : ");

    do
    {

        printf("\t%d", q.Q[i]);
        i = (i + 1) % q.size;

    } while (i != (q.rear + 1) % q.size);
}
