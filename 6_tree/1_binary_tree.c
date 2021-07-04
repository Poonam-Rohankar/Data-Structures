#include "queue.h"

struct Node *root = NULL;

void Treecreate()
{
    struct Node *p, *t;
    int x;
    struct Queue q;
    create(&q, 100);

    printf("Eneter root value ");
    scanf("%d", &x);
    root = (struct Node *)malloc(sizeof(struct Node));
    root->data = x;
    root->lchild = root->rchild = NULL;
    enqueue(&q, root);

    while (!isEmpty(q))
    {
        p = dequeue(&q);
        printf("eneter left child of %d ", p->data);
        scanf("%d", &x);
        if (x != -1)
        {
            t = (struct Node *)malloc(sizeof(struct Node));
            t->data = x;
            t->lchild = t->rchild = NULL;
            p->lchild = t;
            enqueue(&q, t);
        }

        printf("eneter right child of %d ", p->data);
        scanf("%d", &x);
        if (x != -1)
        {
            t = (struct Node *)malloc(sizeof(struct Node));
            t->data = x;
            t->lchild = t->rchild = NULL;
            p->rchild = t;
            enqueue(&q, t);
        }
    }
}
void Preorder(struct Node *p)
{
    if (p)
    {
        printf("%d ", p->data);
        Preorder(p->lchild);
        Preorder(p->rchild);
    }
}

void Inorder(struct Node *p)
{
    if (p)
    {
        Inorder(p->lchild);
        printf("%d ", p->data);
        Inorder(p->rchild);
    }
}
void Postorder(struct Node *p)
{
    if (p)
    {
        Postorder(p->lchild);
        Postorder(p->rchild);
        printf("%d ", p->data);
    }
}

// Level Order transversal
void levelOrder(struct Node *p)
{
    struct Queue q;
    create(&q, 100);

    printf("%d ", p->data);
    enqueue(&q, p);

    while (!isEmpty(q))
    {
        p = dequeue(&q); // deque address of last node

        if (p->lchild)
        {
            printf("%d ", p->lchild->data);
            enqueue(&q, p->lchild);
        }
        if (p->rchild)
        {
            printf("%d ", p->rchild->data);
            enqueue(&q, p->rchild);
        }
    }
}


int Height(struct Node *root)
{
    int x = 0, y = 0;

    if (root == 0)
    {
        return 0;
    }
    else
    {
        x = Height(root->lchild);
        y = Height(root->rchild);
    }
    return x > y ? x + 1 : y + 1;
}

int main()
{
    Treecreate();
    printf("\nInorder : ");
    Inorder(root);
    printf("\nPre Order : ");
    Preorder(root);
    printf("\nPost Order : ");
    Postorder(root);

    printf("\nHeight is : %d", Height(root));
    printf("\nLevel Order : ");
    levelOrder(root);
    return 0;
}