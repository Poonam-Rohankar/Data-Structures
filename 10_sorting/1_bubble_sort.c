// ! Wap to implement bubble sort

#include <stdio.h>
#include <stdlib.h>

void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

void Bubble_Sort(int A[], int n)
{
    int i, j, flag = 0;

    for (i = 0; i < n - 1; i++)
    {
        flag = 0;
        for (j = 0; j < n - i - 1; j++)
        {
            if (A[j] > A[j + 1])
            {
                swap(&A[j], &A[j + 1]);
                flag = 1;
            }
        }
        if (flag == 0)
            break;
    }
}

int main()
{
    int A[] = {12, 12, 67, 13, 11, 4};

    Bubble_Sort(A, 6);

    printf("\nAfter Sorting : ");

    for (int i = 0; i < 6; i++)
    {
        printf("\t%d", A[i]);
    }

    return 0;
}