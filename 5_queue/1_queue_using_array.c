// ! Write a program to implement queue using array

/*
TODO ------
* 1. Enqueue (insert into queue)
* 2. Dequeue (delee from queue)
* 3. isEmpty (check if queue is empty or not)
* 4. isFull (check if queue is full or not)
* 5. Get first Element
* 6. Get Last Element
*/

#include <stdio.h>
#include <stdlib.h>

struct Queue
{
    int size;
    int front; // ? for dequeue
    int rear;  // ? for enqueue
    int *Q;
};

void enqueue(struct Queue *q, int);
void dequeue(struct Queue *q);
void display(struct Queue *q);
int isEmpty(struct Queue *q);
int isFull(struct Queue *q);
int getfront(struct Queue *q);
int getrear(struct Queue *q);

int main()
{
    struct Queue q;

    printf("Enter Size of queue : ");
    scanf("%d", &q.size);

    // ! create array of size
    q.Q = (int *)malloc(q.size * sizeof(int));

    q.front = q.rear = -1; // ! initially queue is empty

    enqueue(&q, 1);
    enqueue(&q, 2);
    enqueue(&q, 3);
    enqueue(&q, 4);
    enqueue(&q, 5);

    display(&q);

    dequeue(&q);

    display(&q);

    if (isEmpty(&q))
    {
        printf("\nQueue is Empty");
    }

    if (isFull(&q))
    {
        printf("\nQueue is Full");
    }

    printf("\nFirst element is %d", getfront(&q));
    printf("\nLast element is %d", getrear(&q));

    return 0;
}

void enqueue(struct Queue *q, int x)
{
    if (q->rear == q->size - 1) //  ? Check for queue is full or not

    {
        printf("\nQueue is Full !");
    }
    else
    {
        q->rear++;
        q->Q[q->rear] = x;
    }
}

void dequeue(struct Queue *q)
{
    int x = -1;
    // ? check for empty queue
    if (q->front == q->rear)
    {
        printf("\nQueue is Empty !");
    }
    else
    {
        q->front++;
        x = q->Q[q->front];
    }

    printf("\nDeleted %d", x);
}

int isEmpty(struct Queue *q)
{
    return (q->front == q->rear);
}

int isFull(struct Queue *q)
{
    return (q->rear == q->size - 1);
}

int getfront(struct Queue *q)
{

    return (q->Q[q->front + 1]);
}

int getrear(struct Queue *q)
{
    return (q->Q[q->rear]);
}

void display(struct Queue *q)
{
    int i;
    printf("\nQueue is : ");
    for (i = q->front + 1; i <= q->rear; i++)
    {
        printf("\t%d", q->Q[i]);
    }
}
