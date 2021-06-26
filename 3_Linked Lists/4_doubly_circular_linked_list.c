// * Write a program to create a circular doubly linked list and perform insertions and deletions at the beginning and end of the list.

#include <stdio.h>
#include <malloc.h>

struct Node
{
    struct Node *next;
    int data;
    struct Node *prev;
};
struct Node *head = NULL;
struct Node *create_ll(struct Node *);
struct Node *display(struct Node *);
struct Node *insert_beg(struct Node *);
struct Node *insert_end(struct Node *);
struct Node *delete_beg(struct Node *);
struct Node *delete_end(struct Node *);
struct Node *delete_Node(struct Node *);
struct Node *delete_list(struct Node *);
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
        printf("\n 5: Delete a Node from the beginning");
        printf("\n 6: Delete a Node from the end");
        printf("\n 7: Delete a given Node");
        printf("\n 8: Delete the entire list");
        printf("\n 9: EXIT");

        printf("\n\n Enter your option : ");
        scanf("%d", &option);

        switch (option)
        {
        case 1:
            head = create_ll(head);
            printf("\n CIRCULAR DOUBLY LINKED LIST CREATED");
            break;
        case 2:
            head = display(head);
            break;
        case 3:
            head = insert_beg(head);
            break;
        case 4:
            head = insert_end(head);
            break;
        case 5:
            head = delete_beg(head);
            break;
        case 6:
            head = delete_end(head);
            break;
        case 7:
            head = delete_Node(head);
            break;
        case 8:
            head = delete_list(head);
            printf("\n CIRCULAR DOUBLY LINKED LIST DELETED");
            break;
        }
    } while (option != 9);
    return 0;
}
struct Node *create_ll(struct Node *head)
{
    struct Node *new_Node, *ptr;
    int num;
    printf("\n Enter –1 to end");
    printf("\n Enter the data : ");
    scanf("%d", &num);
    while (num != -1)
    {
        if (head == NULL)
        {
            new_Node = (struct Node *)malloc(sizeof(struct Node));
            new_Node->prev = NULL;
            new_Node->data = num;
            new_Node->next = head;
            head = new_Node;
        }
        else
        {
            new_Node = (struct Node *)malloc(sizeof(struct Node));
            new_Node->data = num;
            ptr = head;
            while (ptr->next != head)
                ptr = ptr->next;
            new_Node->prev = ptr;
            ptr->next = new_Node;
            new_Node->next = head;
            head->prev = new_Node;
        }
        printf("\n Enter the data : ");
        scanf("%d", &num);
    }

    return head;
}

struct Node *display(struct Node *head)
{
    struct Node *ptr;
    ptr = head;
    while (ptr->next != head)
    {
        printf("\t %d", ptr->data);
        ptr = ptr->next;
    }
    printf("\t %d", ptr->data);
    return head;
}
struct Node *insert_beg(struct Node *head)
{
    struct Node *new_Node, *ptr;
    int num;
    printf("\n Enter the data : ");
    scanf("%d", &num);
    new_Node = (struct Node *)malloc(sizeof(struct Node));
    new_Node->data = num;
    ptr = head;
    while (ptr->next != head)
        ptr = ptr->next;
    new_Node->prev = ptr;
    ptr->next = new_Node;
    new_Node->next = head;
    head->prev = new_Node;
    head = new_Node;
    return head;
}
struct Node *insert_end(struct Node *head)
{
    struct Node *ptr, *new_Node;
    int num;
    printf("\n Enter the data : ");
    scanf("%d", &num);
    new_Node = (struct Node *)malloc(sizeof(struct Node));
    new_Node->data = num;
    ptr = head;
    while (ptr->next != head)
        ptr = ptr->next;
    ptr->next = new_Node;
    new_Node->prev = ptr;
    new_Node->next = head;
    head->prev = new_Node;
    return head;
}

struct Node *delete_beg(struct Node *head)
{
    struct Node *ptr, *temp;
    ptr = head;
    while (ptr->next != head)
        ptr = ptr->next;
    ptr->next = head->next;
    temp = head;
    head = head->next;
    head->prev = ptr;
    free(temp);
    return head;
}

struct Node *delete_end(struct Node *head)
{
    struct Node *ptr;
    ptr = head;
    while (ptr->next != head)
        ptr = ptr->next;
    ptr->prev->next = head;
    head->prev = ptr->prev;
    free(ptr);
    return head;
}
struct Node *delete_Node(struct Node *head)
{
    struct Node *ptr;
    int val;
    printf("\n Enter the value of the Node which has to be deleted : ");
    scanf("%d", &val);
    ptr = head;
    if (ptr->data == val)
    {
        head = delete_beg(head);
        return head;
    }
    else
    {
        while (ptr->data != val)
            ptr = ptr->next;
        ptr->prev->next = ptr->next;
        ptr->next->prev = ptr->prev;
        free(ptr);
        return head;
    }
}


struct Node *delete_list(struct Node *head)
{
    struct Node *ptr;
    ptr = head;
    while (ptr->next != head)
        head = delete_end(head);
    free(head);
    return head;
}