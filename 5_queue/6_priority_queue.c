//  ! Write a program to implement a priority queue

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    int priority;
    struct Node *next;
};

struct Node *front = NULL;
struct Node *enqueue(struct Node *);
struct Node *dequeue(struct Node *);

void display(struct Node *);

int main()
{
    int choice;

    do
    {

        printf("\n-------MAIN MENU-------");
        printf("\n1. Enqueue");
        printf("\n2. Dequeue");
        printf("\n3. Display");
        printf("\n4. Exit");

        printf("\nEnter Your Choice : ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            front = enqueue(front);
            break;

        case 2:
            front = dequeue(front);
            break;

        case 3:
            display(front);
            break;
        case 4:
            exit(0);
            break;
        }
    } while (choice != 4);

    return 0;
}

struct Node *enqueue(struct Node *front)
{
    struct Node *new_new, *ptr = front;
    int val, priority;

    printf("\nEnter the value & its priority : ");
    scanf("%d %d", &val, &priority);

    new_new = (struct Node *)malloc(sizeof(struct Node));
    new_new->data = val;
    new_new->priority = priority;
    new_new->next = NULL;

    if (front == NULL || priority < front->priority)
    {
        new_new->next = front;
        front = new_new;
    }
    else
    {
        while (ptr->next != NULL && ptr->next->priority <= priority)
        {
            ptr = ptr->next;
        }

        new_new->next = ptr->next;
        ptr->next = new_new;
    }

    return front;
}

struct Node *dequeue(struct Node *front)
{
    struct Node *temp;
    if (front == NULL)
    {
        printf("\nQueue is Empty !");
    }
    else
    {
        temp = front;
        front = front->next;
        printf("\nDequeued %d", temp->data);
        free(temp);
    }

    return front;
}

void display(struct Node *front)
{

    struct Node *ptr = front;
    printf("\nQueue is : ");
    while (ptr != NULL)
    {
        printf("\t%d", ptr->data);
        ptr = ptr->next;
    }
}
