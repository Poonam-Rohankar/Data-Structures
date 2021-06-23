/*Write a program to create a linked list and perform insertions and deletions of all cases.
Write functions to sort and finally delete the entire list at once. */

#include <stdio.h>
#include <stdlib.h>

// Node
struct Node
{
    int data;
    struct Node *next; // pointer to next node
};

struct Node *head = NULL; // Head Pointer Pointing to first node

struct Node *create_linked_list(struct Node *); // create Linked List

struct Node *display(struct Node *); // display linked List

struct Node *insertBeginning(struct Node *); // insert Node at Beginning

struct Node *insertEnd(struct Node *); // insert Node at end

// Main
int main()
{
    int choice;

    do
    {
        printf("\n\n * ****MAIN MENU * **** ");
        printf("\n1. Create Linked List");
        printf("\n2. Display Linked List");
        printf("\n3. Insert Node at beginning");
        printf("\n4. Insert Node at end");

        printf("\nEnter your choice : ");
        scanf("%d", &choice);

        // switch
        switch (choice)
        {
        case 1:
        {
            head = create_linked_list(head);
            printf("\nLinked List Created");
            break;
        }
        case 2:
        {
            printf("\nLinked List is : ");
            head = display(head);
            break;
        }
        case 3:
        {
            head = insertBeginning(head);
            printf("\nNode inserted at Beginning");
            break;
        }
        case 4:
        {
            head = insertEnd(head);
            break;
        }
        default:
        {
            printf("\nInvalid Input");
        }
        }
    } while (choice != 0);
}

struct Node *create_linked_list(struct Node *head)
{
    struct Node *new_node, *ptr;
    int num;
    printf("\nEnter -1 to end");
    printf("\nEnter Data : ");
    scanf("%d", &num);

    while (num != -1)
    {
        new_node = (struct Node *)malloc(sizeof(struct Node));
        new_node->data = num;
        new_node->next = NULL;

        if (head == NULL) // if list is empy
        {
            head = new_node;
        }
        else
        {
            ptr = head;

            // reach last node
            while (ptr->next != NULL)
            {
                ptr = ptr->next;
            }

            ptr->next = new_node;
        }

        // again get input
        printf("\nEnter Data : ");
        scanf("%d", &num);
    }

    return head;
}

struct Node *display(struct Node *head)
{
    struct Node *ptr = head;

    while (ptr != NULL)
    {
        printf("%d\t", ptr->data);
        ptr = ptr->next;
    }
    return head;
}

struct Node *insertBeginning(struct Node *head)
{
    struct Node *new_node;
    int num;
    printf("\nEnter data : ");
    scanf("%d", &num);

    new_node = (struct Node *)malloc(sizeof(struct Node));
    new_node->data = num;
    new_node->next = NULL;

    if (head == NULL)
    {
        head = new_node;
    }
    else
    {
        new_node->next = head;
        head = new_node;
    }

    return head;
}

struct Node *insertEnd(struct Node *head)
{
    struct Node *new_node, *ptr;
    int num;
    printf("\nEnter Data : ");
    scanf("%d", &num);

    new_node = (struct Node *)malloc(sizeof(struct Node));
    new_node->data = num;
    new_node->next = NULL;

    if (head == NULL)
    {
        head = new_node;
    }
    else
    {
        ptr = head;
        while (ptr->next != NULL)
        {
            ptr = ptr->next;
        }

        ptr->next = new_node;
    }

    return head;
} // insert Node at end
