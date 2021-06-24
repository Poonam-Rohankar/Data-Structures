/*
! Write a program to create a linked list and perform insertions and deletions of all cases.
! Write functions to sort and finally delete the entire list at once. 
*/

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

struct Node *insertBefore(struct Node *); // insert node before specific node

struct Node *insertAfter(struct Node *); // insert node after specific node

struct Node *deleteBeginning(struct Node *); // delete first node or node from beginning

struct Node *deleteEnd(struct Node *); // delete last Node

struct Node *deleteNode(struct Node *); // delete node by its value

// Main
int main()
{
    int choice;

    do
    {
        // ------------------------
        printf("\n\n * ****MAIN MENU * **** ");
        printf("\n1. Create Linked List");
        printf("\n2. Display Linked List");
        printf("\n3. Insert Node at beginning");
        printf("\n4. Insert Node at end");
        printf("\n5. Insert Node before a given node");
        printf("\n6. Insert Node after a given node");
        printf("\n7. Delete Node from beginning");
        printf("\n8. Delete Node from end");
        printf("\n9. Delete node by value");
        // -------------------------
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
        case 5:
        {
            head = insertBefore(head);
            break;
        }
        case 6:
        {
            head = insertAfter(head);
            break;
        }
        case 7:
        {
            head = deleteBeginning(head);
            break;
        }
        case 8:
        {
            head = deleteEnd(head);
            break;
        }
        case 9:
        {
            head = deleteNode(head);
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

struct Node *insertBefore(struct Node *head)
{
    struct Node *new_node, *previous, *ptr = head;
    int num, val;

    printf("\nEnter Data : ");
    scanf("%d", &num);

    printf("\n Enter the value before which the data has to be inserted : ");
    scanf("%d", &val);

    new_node = (struct Node *)malloc(sizeof(struct Node));
    new_node->data = num;

    while (ptr->data != val)
    {
        previous = ptr; // pointer following current pointer
        ptr = ptr->next;
    }

    previous->next = new_node; //  previous node pointing  to new node
    new_node->next = ptr;      // new node pointing to next node

    return head;
}

struct Node *insertAfter(struct Node *head)
{
    struct Node *new_node, *ptr = head;
    int num, val;

    printf("\Enter Data : ");
    scanf("%d", &num);

    printf("\n Enter the value after which the data has to be inserted : ");
    scanf("%d", &val);

    new_node = (struct Node *)malloc(sizeof(struct Node));
    new_node->data = num;
    new_node->next = NULL;

    while (ptr->data != val)
    {
        ptr = ptr->next;
    }

    new_node->next = ptr->next; // new node pointing to next node of current node
    ptr->next = new_node;       // current node pointing to new_node

    return head;
}

struct Node *deleteBeginning(struct Node *head)
{
    struct Node *temp;

    temp = head; // point temp to head
    head = head->next;
    printf("\nDeleted %d", temp->data);

    free(temp); // free temp pointer
    return head;
}

struct Node *deleteEnd(struct Node *head)
{
    struct Node *previous, *ptr = head;

    while (ptr->next != NULL)
    {
        previous = ptr;
        ptr = ptr->next;
    }

    printf("\nDeleted %d", previous->data);
    previous->next = NULL;
    free(ptr);

    return head;
}

struct Node *deleteNode(struct Node *head)
{
    struct Node *ptr = head, *previous;
    int val;
    printf("\nEnter the value has to be deleted : ");
    scanf("%d", &val);

    // if only one node in list
    if (ptr->data == val)
    {
        head = deleteBeginning(head); // delete first node
        return head;
    }
    else
    {
        while (ptr->data != val)
        {
            previous = ptr;
            ptr = ptr->next;
        }

        previous->next = ptr->next; // previous node pointing to next node of currentt node
        printf("\nDeleted  %d", ptr->data);
        free(ptr);

        return head;
    }
}
