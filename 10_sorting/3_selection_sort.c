//  ! Wap to implement selection sort

#include <stdio.h>

void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

void selection_sort(int A[], int n)
{
    int i, j, k;

    for (int i = 0; i < n - 1; i++)
    {
        for (j = k = i; j < n; j++) // initially j & k pointing on i
        {
            if (A[j] < A[k]) // compare j & k if j element is > k
            {
                k = j; // then k assign j
            }
        }

        swap(&A[i], &A[k]); // swap ith element kth element
    }
}


int main()
{
    int A[] = {23, 11, 34, 3, 1, 43, 24}, n = 7;

    selection_sort(A, n);

    printf("\nAfter Selection Sort : ");
    for (int i = 0; i < n; i++)
    {
        printf("\t%d", A[i]);
    }

    return 0;
}