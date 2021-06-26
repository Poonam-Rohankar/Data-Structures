// !  Write a program to implement a header linked list.

/*
 * A header linked list is a special type of linked list which contains a header node at the beginning of the list. So, in a header linked list, START will not point to the first node of the list but START will contain the address of the header node. The following are the two variants of a header linked list: 
*/

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *head = NULL; // hader pointer

struct Node *create_linked_list(struct Node *);

struct Node *display(struct Node *);

int main()
{
    int choice;

    do
    {
        printf("\n----MAIN MENU ---");
        printf("\n1. Create Linked List");
        printf("\n2. Display");
        printf("\n3. Exit");

        printf("\nEnter your choice : ");
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
            exit(0);
            break;
        }
        default:
        {
            printf("\n Invalid Input !");
        }
        }
    } while (choice != 3);

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
        new_node->next = NULL;

        if (head == NULL)
        {
            head = (struct Node *)malloc(sizeof(struct Node));
            head->next = new_node;
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
        printf("\nEnter -1 to exit");
        printf("\nEnter data : ");
        scanf("%d", &num);
    }
    return head;
}

struct Node *display(struct Node *head)
{
    struct Node *ptr = head;
    printf("\nList is :");
    while (ptr != NULL)
    {
        printf("\t%d", ptr->data);
        ptr = ptr->next;
    }

    return head;
}