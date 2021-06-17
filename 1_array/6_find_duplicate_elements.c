// 6. Write a program to find whether the array of integers contains a duplicate number.

#include <stdio.h>

int main()
{
    int i, j, n, count = 0;

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

    // find Duplicates and print
    for (i = 0; i < n; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (arr[i] == arr[j])
            {
                count = 1;
                printf("\nDuplicate elements found at position %d abd %d", i, j);
            }
        }
    }

    // if no duplicates found
    if (count == 0)
    {
        printf("\nNo Duplicates Found");
    }
    return 0;
}