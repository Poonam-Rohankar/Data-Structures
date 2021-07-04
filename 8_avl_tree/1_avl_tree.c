#include <stdlib.h>
#include <stdio.h>

struct Node
{
    struct Node *lchild;
    int data;
    int height;
    struct Node *rchild;
} *root = NULL;

// Height of Node
int Height(struct Node *p)
{
    int hl, hr;

    hl = p && p->lchild ? p->lchild->height : 0;

    hr = p && p->rchild ? p->rchild->height : 0;

    return hl > hr ? hl + 1 : hr + 1;
}

// Balance Factor
int BalanceFactor(struct Node *p)
{
    int hl, hr;

    hl = p && p->lchild ? p->lchild->height : 0;
    hr = p && p->rchild ? p->rchild->height : 0;

    return hl - hr;
}

// LL Rotation
struct Node *LLRotation(struct Node *p)
{
    struct Node *pl = p->lchild;
    struct Node *plr = pl->rchild;

    pl->rchild = p;

    p->height = Height(p);
    pl->height = Height(pl);

    if (root == p)
    {
        root = pl;
    }

    return pl;
}

// LR Rotation
struct Node *LRRotation(struct Node *p)
{
    struct Node *pl = p->lchild;
    struct Node *plr = pl->rchild;

    pl->rchild = plr->lchild;
    p->lchild = plr->rchild;

    pl->height = Height(pl);
    p->height = Height(p);
    plr->height = Height(plr);

    if (root == p)
    {
        root = plr;
    }
    return plr;
}

// Insert
struct Node *Insert(struct Node *p, int key)
{
    struct Node *new_node;

    if (p == NULL)
    {
        new_node = (struct Node *)malloc(sizeof(new_node));
        new_node->data = key;
        new_node->height = 1;
        new_node->lchild = new_node->rchild = NULL;

        return new_node;
    }

    if (key < p->data)
    {
        p->lchild = Insert(p->lchild, key);
    }
    else if (key > p->data)
    {
        p->rchild = Insert(p->rchild, key);
    }

    p->height = Height(p);

    if (BalanceFactor(p) == 2 && BalanceFactor(p->lchild) == 1)
    {
        return LLRotation(p);
    }
    else if (BalanceFactor(p) == 2 && BalanceFactor(p->lchild) == -1)
    {
        return LRRotation(p);
    }

    return p;
}

int main()
{
    root = Insert(root, 10);
    Insert(root, 9);
    Insert(root, 5);

    return 0;
}