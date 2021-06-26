// * Write a program to create a doubly linked list and perform insertions and deletions in all cases.

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    struct Node *prev;
    int data;
    struct Node *next;
};

struct Node *head = NULL; // head pointer

struct Node *create_ll(struct Node *); // create linked list

struct Node *display(struct Node *); // display all nodes

struct Node *insert_beginning(struct Node *); // insert node before head node

struct Node *insert_end(struct Node *); // insert after last node

struct Node *insert_before(struct Node *); // insert node before given node

struct Node *insert_after(struct Node *); // insert node after given node

struct Node *delete_beginning(struct Node *); // delete first node

struct Node *delete_end(struct Node *); // delete last node

struct Node *delete_before(struct Node *); // delete node before given node

struct Node *delete_after(struct Node *); // delete node after given node

struct Node *delete_list(struct Node *); // delete att nodes

int main()
{
    int option;
    do
    {
        printf("\n\n *****MAIN MENU *****");
        printf("\n 1: Create a list");
        printf("\n 2: Display the list");
        printf("\n 3: Add a Node at the beginning");
        printf("\n 4: Add a Node at the end");
        printf("\n 5: Add a Node before a given Node");
        printf("\n 6: Add a Node after a given Node");
        printf("\n 7: Delete a Node from the beginning");
        printf("\n 8: Delete a Node from the end");
        printf("\n 9: Delete a Node before a given Node");
        printf("\n 10: Delete a Node after a given Node");
        printf("\n 11: Delete the entire list");
        printf("\n 12: EXIT");
        printf("\n\n Enter your option : ");
        scanf("%d", &option);
        switch (option)
        {
        case 1:
        {
            head = create_ll(head);
            printf("\n DOUBLY LINKED LIST CREATED");
            break;
        }
        case 2:
        {
            head = display(head);
            break;
        }
        case 3:
        {
            head = insert_beginning(head);
            break;
        }
        case 4:
        {
            head = insert_end(head);
            break;
        }
        case 5:
        {
            head = insert_before(head);
            break;
        }
        case 6:
        {
            head = insert_after(head);
            break;
        }
        case 7:
        {
            head = delete_beginning(head);
            break;
        }
        case 8:
        {
            head = delete_end(head);
            break;
        }
        case 9:
        {
            head = delete_before(head);
            break;
        }
        case 10:
        {
            head = delete_after(head);
            break;
        }
        case 11:
        {
            head = delete_list(head);
            break;
        }
        }
    } while (option != 12);
    return 0;
}

struct Node *create_ll(struct Node *head)
{
    struct Node *new_node, *ptr;
    int num;
    printf("\n Enter –1 to end");
    printf("\n Enter the data : ");
    scanf("%d", &num);
    while (num != -1)
    {
        if (head == NULL)
        {
            new_node = (struct Node *)malloc(sizeof(struct Node));
            new_node->prev = NULL;
            new_node->data = num;
            new_node->next = NULL;
            head = new_node;
        }
        else
        {
            ptr = head;
            new_node = (struct Node *)malloc(sizeof(struct Node));
            new_node->data = num;
            while (ptr->next != NULL)
            {
                ptr = ptr->next;
            }
            ptr->next = new_node;
            new_node->prev = ptr;
            new_node->next = NULL;
        }
        printf("\n Enter the data : ");
        scanf("%d", &num);
    }
    return head;
}

struct Node *display(struct Node *head)
{
    struct Node *ptr = head;
    printf("\nDoubly linked list is :");
    while (ptr != NULL)
    {
        printf("\t %d", ptr->data);
        ptr = ptr->next;
    }
    return head;
}

struct Node *insert_beginning(struct Node *head)
{
    struct Node *new_node;
    int num;
    printf("\nEnter data : ");
    scanf("%d", &num);

    new_node = (struct Node *)malloc(sizeof(struct Node));
    new_node->data = num;

    head->prev = new_node;
    new_node->next = head;
    new_node->prev = NULL;

    head = new_node;

    return head;
}

struct Node *insert_end(struct Node *head)
{
    struct Node *new_node, *ptr = head;
    int num;

    printf("\nEnter data : ");
    scanf("%d", &num);

    new_node = (struct Node *)malloc(sizeof(struct Node));
    new_node->data = num;

    while (ptr->next != NULL)
    {
        ptr = ptr->next;
    }

    ptr->next = new_node;
    new_node->prev = ptr;
    new_node->next = NULL;

    return head;
}

struct Node *insert_before(struct Node *head)
{
    struct Node *new_node, *ptr = head;
    int num, val;

    printf("\nEnter data : ");
    scanf("%d", &num);

    printf("\nEnter the value before which the data has to be inserted : ");
    scanf("%d", &val);

    new_node = (struct Node *)malloc(sizeof(struct Node));
    new_node->data = num;

    while (ptr->data != val)
    {
        ptr = ptr->next;
    }

    new_node->next = ptr;
    new_node->prev = ptr->prev;
    ptr->prev->next = new_node;
    ptr->prev = new_node;

    return head;
}

struct Node *insert_after(struct Node *head)
{
    struct Node *new_node, *ptr = head;
    int num, val;

    printf("\nEnter data : ");
    scanf("%d", &num);

    printf("\nEnter the value after which the data has to be inserted : ");
    scanf("%d", &val);

    new_node = (struct Node *)malloc(sizeof(struct Node));
    new_node->data = num;

    while (ptr->data != val)
    {
        ptr = ptr->next;
    }

    new_node->prev = ptr;
    new_node->next = ptr->next;
    ptr->next->prev = new_node;
    ptr->next = new_node;

    return head;
}

struct Node *delete_beginning(struct Node *head)
{
    struct Node *ptr = head;

    head = head->next;
    head->prev = NULL;

    printf("\nDeleting %d", ptr->data);
    free(ptr);

    return head;
}

struct Node *delete_end(struct Node *head)
{
    struct Node *ptr = head;

    while (ptr->next != NULL)
    {
        ptr = ptr->next;
    }

    ptr->prev->next = NULL;
    ptr->prev = NULL;

    printf("\nDeleting %d", ptr->data);
    free(ptr);

    return head;
}

struct Node *delete_before(struct Node *head)
{
    struct Node *previous, *ptr = head;
    int val;
    printf("\n Enter the value before which the node has to deleted : ");
    scanf("%d", &val);

    while (ptr->data != val)
    {
        ptr = ptr->next;
    }
    previous = ptr->prev; // follow

    if (ptr == head)
    {
        return head;
    }
    else
    {

        if (previous->prev != NULL)
        {
            printf("\nDeleting %d", previous->data);
            ptr->prev = previous->prev;
            previous->prev->next = ptr;
        }
        else
        {
            head = delete_beginning(head);
        }
        free(previous);
    }

    return head;
}

struct Node *delete_after(struct Node *head)
{
    struct Node *temp, *ptr = head;
    int val;
    printf("\n Enter the value after which the node has to deleted : ");
    scanf("%d", &val);

    while (ptr->data != val)
    {
        ptr = ptr->next;
    }
    temp = ptr->next;

    if (temp->next == NULL) // if node node after curent node of next of next
    {
        head = delete_end(head);
    }
    else
    {
        ptr->next = temp->next;
        temp->next->prev = ptr;
        printf("\nDeleting %d", temp->data);
        free(temp);
    }

    return head;
}

struct Node *delete_list(struct Node *head)
{
    while (head != NULL)
    {
        head = delete_beginning(head);
    }

    return 0;
}