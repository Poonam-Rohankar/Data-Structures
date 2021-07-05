// TODO__ Wap to implement recursive merge sort

#include <stdio.h>

void merge(int A[], int low, int mid, int high)
{
    int i = low, j = mid + 1, k = low;
    int Merged[100];

    while (i <= mid && j <= high)
    {
        if (A[i] < A[j])
        {
            Merged[k++] = A[i++];
        }
        else
        {
            Merged[k++] = A[j++];
        }
    }

    // if elements remains in any one of list

    for (; i <= mid; i++)
    {
        Merged[k++] = A[i];
    }

    for (; j <= high; j++)
    {
        Merged[k++] = A[j];
    }

    // * Comperged Merged  Array into original aray
    for (i = low; i <= high; i++)
    {
        A[i] = Merged[i];
    }
}

void recursive_merge_sort(int A[], int low, int high)
{
    int mid;

    if (low < high)
    {
        mid = (low + high) / 2;

        // sort recursively
        recursive_merge_sort(A, low, mid);
        recursive_merge_sort(A, mid + 1, high);

        // Now merrge
        merge(A, low, mid, high);
    }
}

int main()
{
    int A[] = {98, 34, 12, 32, 1, 65, 786};

    recursive_merge_sort(A, 0, 7);

    printf("\nAfter Recursive Merge Sort : ");
    for (int i = 0; i < 7; i++)
    {
        printf("\t%d", A[i]);
    }

    return 0;
}