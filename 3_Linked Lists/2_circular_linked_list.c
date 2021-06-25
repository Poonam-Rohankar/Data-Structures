// * Write a program to create a circular linked list. Perform insertion and deletion

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *head = NULL; // head pointer pointing to first node

struct Node *create_linked_list(struct Node *); // create linked list

struct Node *display(struct Node *); // display all nodes

struct Node *insertBeginning(struct Node *); // insert node at bginning

struct Node *insertEnd(struct Node *); // insert node at end

struct Node *deleteBeginning(struct Node *); // delete first node

struct Node *deleteEnd(struct Node *); // delete last node

struct Node *deleteAfter(struct Node *); // delete node after specific node

struct Node *deleteAll(struct Node *); // delete all nodes at a time

// ! ------------ MAIN -----------------

int main()
{
    int choice;

    do
    {
        printf("\n\n *****MAIN MENU *****");
        printf("\n0. Exit");
        printf("\n 1. Create a list");
        printf("\n 2. Display the list");
        printf("\n 3. Insert a node at the beginning");
        printf("\n 4. Insert a node at the end");
        printf("\n 5. Delete a node from the beginning");
        printf("\n 6. Delete a node from the end");
        printf("\n 7. Delete a node after a given node");
        printf("\n 8. Delete the entire list");

        printf("\n\nEnter your choice : ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
        {
            head = create_linked_list(head);
            break;
        }
        case 2:
        {
            head = display(head);
            break;
        }
        case 3:
        {
            head = insertBeginning(head);
            break;
        }
        case 4:
        {
            head = insertEnd(head);
            break;
        }
        case 5:
        {
            head = deleteBeginning(head);
            break;
        }
        case 6:
        {
            head = deleteEnd(head);
            break;
        }
        case 7:
        {
            head = deleteAfter(head);
            break;
        }
        case 8:
        {
            head = deleteAll(head);
            break;
        }
        default:
        {
            exit(0);
        }
        }

    } while (choice != 0);

    return 0;
}

struct Node *create_linked_list(struct Node *head)
{
    struct Node *new_node, *ptr;
    int num;

    printf("\nEnter -1 to exit");
    printf("\nEnter data : ");
    scanf("%d", &num);

    while (num != -1)
    {
        new_node = (struct Node *)malloc(sizeof(struct Node));
        new_node->data = num;

        if (head == NULL)
        {
            new_node->next = new_node;
            head = new_node;
        }
        else
        {
            ptr = head;

            while (ptr->next != head)
            {
                ptr = ptr->next;
            }
            // append node at end
            ptr->next = new_node;
            new_node->next = head; // point last node to head to make circular queue
        }
        // again take input data
        printf("\nEnter data : ");
        scanf("%d", &num);
    }
    return head;
}

struct Node *display(struct Node *head)
{
    struct Node *ptr = head;

    printf("\nCircular linked list is :");
    while (ptr->next != head)
    {
        printf("\t%d", ptr->data);
        ptr = ptr->next;
    }
    printf("\t%d", ptr->data); // print last remaining node

    return head;
}

struct Node *insertBeginning(struct Node *head)
{
    struct Node *new_node, *ptr = head;
    int num;
    printf("\nEnter data : ");
    scanf("%d", &num);

    new_node = (struct Node *)malloc(sizeof(struct Node));
    new_node->data = num;

    // reach to previous node of first node which is next to last node
    while (ptr->next != head)
    {
        ptr = ptr->next;
    }

    ptr->next = new_node;
    new_node->next = head;
    head = new_node; // modify head to new node

    return head;
}

struct Node *insertEnd(struct Node *head)
{
    struct Node *new_node, *ptr = head;
    int num;
    printf("\nEnter data : ");
    scanf("%d", &num);

    new_node = (struct Node *)malloc(sizeof(struct Node));
    new_node->data = num;

    // reach to last node
    while (ptr->next != head)
    {
        ptr = ptr->next;
    }

    ptr->next = new_node;
    new_node->next = head;

    return head;
}

struct Node *deleteBeginning(struct Node *head)
{
    struct Node *ptr = head;

    while (ptr->next != head)
    {
        ptr = ptr->next;
    }

    printf("\nDeleting %d", head->data);
    ptr->next = head->next;
    free(head);
    head = ptr->next;

    return head;
}

struct Node *deleteEnd(struct Node *head)
{
    struct Node *ptr = head, *previous;

    while (ptr->next != head)
    {
        previous = ptr;
        ptr = ptr->next;
    }
    previous->next = ptr->next;
    printf("\nDeleting %d", ptr->data);
    free(ptr);

    return head;
}

struct Node *deleteAfter(struct Node *head)
{
    struct Node *ptr = head, *previous = ptr;
    int val;

    printf("\nEnter the value after which the node has to be deleted : ");
    scanf("%d", &val);

    while (previous->data != val)
    {
        previous = ptr;
        ptr = ptr->next;
    }

    previous->next = ptr->next;
    printf("Deleting %d", ptr->data);
    if (ptr == head)
    {
        head = previous->next;
    }

    return head;
}

struct Node *deleteAll(struct Node *head)
{
    struct Node *ptr = head;

    while (ptr->next != head)
    {
        head = deleteEnd(head);
    }
    free(head);

    return head;
}