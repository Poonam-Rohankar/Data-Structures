// ! Wap to implement quick sort

#include <stdio.h>

void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

int partition(int A[], int l, int h)
{
    int pivot = A[l]; // select low index element as pivot
    int i = l, j = h;

    do
    {
        do
        {
            i++;
        } while (A[i] <= pivot); // look for greater elements than pivot

        do
        {
            j--;
        } while (A[j] > pivot); // look for smaller elements than pivot

        if (i < j)
        {
            swap(&A[i], &A[j]); // swap if found greather than pivot & saller than pivot
        }

    } while (i < j);

    swap(&A[l], &A[j]);

    return j;
}


void quick_sort(int A[], int l, int h)
{
    int j;

    if (l < h)
    {
        j = partition(A, l, h);
        quick_sort(A, l, j);     // sort elements from low to middle
        quick_sort(A, j + 1, h); // sort elements from middle to last
    }
}

int main()
{
    int A[] = {23, 11, 34, 3, 1, 43, 24}, n = 7;

    quick_sort(A, 0, n - 1);

    printf("\nAfter Quick Sort : ");
    for (int i = 0; i < n; i++)
    {
        printf("\t%d", A[i]);
    }

    return 0;
}