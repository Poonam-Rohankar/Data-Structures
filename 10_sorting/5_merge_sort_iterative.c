// ! Wap a program to implement iterative merge sort

#include <stdio.h>

void merge(int A[], int l, int mid, int h)
{
    int i = l, j = mid + 1, k = l;
    int B[100];

    while (i <= mid && j <= h)
    {
        if (A[i] < A[j])
        {
            B[k++] = A[i++];
        }
        else
        {
            B[k++] = A[j++];
        }
    }

    // if elements left in list 1
    for (; i <= mid; i++)
        B[k++] = A[i];

    // if elements left in list 2
    for (; j <= h; j++)
        B[k++] = A[j];

    // Copy all the elelemnts in A[] after Merging
    for (i = l; i <= h; i++)
        A[i] = B[i];
}

void iterative_merge_sort(int A[], int n)
{
    int p; // for passed
    int l, mid, h, i;

    for (p = 2; p <= n; p = p * 2)
    {
        for (i = 0; i + p - 1 <= n; i = i + p)
        {
            l = i;
            h = i + p - 1;
            mid = (l + h) / 2;

            merge(A, l, mid, h);
        }
    }

    if (p / 2 < n)
    {
        merge(A, 0, p / 2 - 1, n);
    }
}

int main()
{
    int A[] = {23, 11, 34, 3, 1, 43, 24}, n = 7, i;

    iterative_merge_sort(A, n);

    printf("\nAfter Merge  Sort : ");
    for (i = 0; i < n; i++)
    {
        printf("\t%d", A[i]);
    }

    return 0;
}