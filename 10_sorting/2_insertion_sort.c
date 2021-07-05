//  ! Wap to implement insertion sort

#include <stdio.h>

void insertion_sort(int A[], int n)
{
    int i, j, x;

    for (i = 1; i < n; i++)
    {
        j = i - 1;
        x = A[i];

        while (j > -1 && A[j] > x) // comparing element at index i with with all the elements less than index i
        {
            A[j + 1] = A[j]; // right shift
            j--;
        }
        A[j + 1] = x; // finally place ith elemnt at sorted place
    }
}

int main()
{
    int A[] = {23, 12, 54, 34, 10, 2, 78, 16, 0, 90}, n = 10, i;

    insertion_sort(A, n);

    printf("\nAfter Insertion Sort : ");
    for (i = 0; i < n; i++)
    {
        printf("\t%d", A[i]);
    }

    return 0;
}