//  ! write a program to implement binary search tree

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    struct Node *lchild;
    int data;
    struct Node *rchild;
} *root = NULL;

void insert(int key)
{
    struct Node *new_node, *ptr = root, *temp = NULL;

    if (root == NULL)
    {
        new_node = (struct Node *)malloc(sizeof(struct Node));
        new_node->data = key;
        new_node->lchild = new_node->rchild = NULL;
        root = new_node;
        return;
    }

    while (ptr != NULL)
    {
        temp = ptr;

        if (key < ptr->data)
        {
            ptr = ptr->lchild;
        }
        else if (key > ptr->data)
        {
            ptr = ptr->rchild;
        }
        else
        {
            return;
        }
    }

    new_node = (struct Node *)malloc(sizeof(struct Node));
    new_node->data = key;
    new_node->lchild = new_node->rchild = NULL;

    if (key > temp->data)
    {
        temp->rchild = new_node;
    }
    else if (key < temp->data)
    {
        temp->lchild = new_node;
    }
}

struct Node *RInsert(struct Node *ptr, int key)
{
    struct Node *new_node = NULL;

    if (ptr == NULL)
    {
        new_node = (struct Node *)malloc(sizeof(struct Node));
        new_node->data = key;
        new_node->lchild = new_node->rchild = NULL;
        return new_node;
    }

    if (key < ptr->data)
    {
        ptr->lchild = RInsert(ptr->lchild, key);
    }
    else if (key > ptr->data)
    {
        ptr->rchild = RInsert(ptr->rchild, key);
    }
    return ptr;
}

void InOrder(struct Node *ptr)
{
    if (ptr)
    {

        InOrder(ptr->lchild);
        printf("%d\t", ptr->data);
        InOrder(ptr->rchild);
    }
}

struct Node *Search(int key)
{
    struct Node *ptr = root;

    while (ptr != NULL)
    {
        if (key == ptr->data)
        {
            return ptr;
        }
        else if (key < ptr->data)
        {
            ptr = ptr->lchild;
        }
        else if (key > ptr->data)
        {
            ptr = ptr->rchild;
        }
    }
    return NULL;
}

int Height(struct Node *ptr)
{
    int x = 0, y = 0;

    if (ptr == NULL)
        return 0;

    x = Height(ptr->lchild);
    y = Height(ptr->rchild);
    return x > y ? x + 1 : y + 1;
}

struct Node *InOrder_Predecessor(struct Node *ptr)
{
    while (ptr && ptr->rchild != NULL)
        ptr = ptr->rchild;

    return ptr;
}

struct Node *InOrder_Successor(struct Node *ptr)
{
    while (ptr && ptr->lchild != NULL)
        ptr = ptr->lchild;

    return ptr;
}

struct Node *Delete(struct Node *p, int key)
{
    struct Node *q;

    if (p == NULL)
    {
        return NULL;
    }

    if (p->lchild == NULL && p->rchild == NULL)  // if p is leaf node
    {
        if (p == root) // if that is root node
            root = NULL;

        free(p);
        return NULL;
    }

    if (key < p->data)
    {
        p->lchild = Delete(p->lchild, key);
    }
    else if (key > p->data)
    {
        p->rchild = Delete(p->rchild, key);
    }
    else
    {
        if (Height(p->lchild) > Height(p->rchild))
        {
            q = InOrder_Predecessor(p->lchild);
            p->data = q->data;
            p->lchild = Delete(p->lchild, q->data);
        }
        else
        {
            q = InOrder_Successor(p->rchild);
            p->data = q->data;
            p->rchild = Delete(p->rchild, key);
        }
    }

    return p;
}

int main()
{
    struct Node *temp;

    insert(25);
    insert(10);
    insert(20);
    insert(15);
    insert(5);

    InOrder(root);

    printf("\n");
    temp = Search(20);

    if (temp != NULL)
    {
        printf("\n%d is found at %d", temp->data, temp);
    }

    root = RInsert(root, 12);
    RInsert(root, 13);

    printf("\n");
    InOrder(root);

    Delete(root, 15);
    Delete(root, 12);

    printf("\n");
    InOrder(root);

    return 0;
}