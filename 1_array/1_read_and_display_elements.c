// 1. Write a program to read and display n numbers using an array.
#include <stdio.h>

int main()
{
    int i, n;
    printf("Enter Size of Array : ");
    scanf("%d", &n);

    int arr[n];

    // Read
    printf("\nEnter %d elements :\n", n);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    // Display
    printf("\nElements are : ");
    for (i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    return 0;
}