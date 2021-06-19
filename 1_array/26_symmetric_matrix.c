#include <stdio.h>
#include <stdlib.h>
struct Matrix
{
    int *A;
    int n;
};

void Set(struct Matrix *M, int i, int j, int x)
{
    if (i >= j)
    { //formula [i * (i - 1) / 2 + j - 1]
        M->A[i * (i - 1) / 2 + j - 1] = x;
    }
}

int Get(struct Matrix M, int i, int j)
{
    if (i >= j)
    {
        return M.A[i * (i - 1) / 2 + j - 1];
    }
    else
    {
        return M.A[j * (j - 1) / 2 + i - 1];
    }
}

void Display(struct Matrix M)
{
    int i, j;
    for (i = 1; i <= M.n; i++)
    {
        for (j = 1; j <= M.n; j++)
        {
            if (i >= j)
            {
                printf("%d ", M.A[i * (i - 1) / 2 + j - 1]);
            }
            else
            {
                printf("%d ", M.A[j * (j - 1) / 2 + i - 1]);
            }
        }
        printf("\n");
    }
}
// Main
int main()
{
    struct Matrix M;
    int i, j, x;
    printf("Enter Dimension : ");
    scanf("%d", &M.n);
    //Memory Allocation
    M.A = (int *)malloc(M.n * (M.n - 1) / 2 * sizeof(int));

    printf("\nEnter %d x %d elements : ", M.n, M.n);

    for (i = 1; i <= M.n; i++)
    {
        for (j = 1; j <= M.n; j++)
        {
            scanf("%d", &x);
            Set(&M, i, j, x);
        }
    }
    printf("\n");
    Display(M);
    return 0;
}