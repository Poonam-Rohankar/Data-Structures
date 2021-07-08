#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

void SortedInsert(struct Node **H, int x)
{
    struct Node *new_node, *previous = NULL, *ptr = *H;

    new_node = (struct Node *)malloc(sizeof(struct Node));
    new_node->data = x;
    new_node->next = NULL;

    if (*H == NULL)
    {
        *H = new_node;
    }
    else
    {
        while (ptr && ptr->data < x)
        {
            previous = ptr;
            ptr = ptr->next;
        }

        if (ptr == *H) // insert beginning
        {
            new_node->next = *H;
            *H = new_node;
        }
        else // insert before
        {
            new_node->next = previous->next;
            previous->next = new_node;
        }
    }
}

struct Node *Search(struct Node *ptr, int key)
{
    while (ptr != NULL)
    {
        if (key == ptr->data)
        {
            return ptr;
        }
        ptr = ptr->next;
    }
    return NULL;
}
