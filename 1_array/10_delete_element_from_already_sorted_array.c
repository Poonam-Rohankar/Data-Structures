// 10. Write a program to delete a number from an array that is already sorted in ascending order.

#include <stdio.h>

int main()
{
    int arr[20];
    int i, j, n, element;
    printf("Enter Size of Array : ");
    scanf("%d", &n);

    // Read
    printf("\nEnter %d elements :\n", n);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    // Display
    printf("\nElements before insert are : ");
    for (i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    // input element to delete
    printf("\nEnter element to delete : ");
    scanf("%d", &element);

    // delete element
    for (i = 0; i < n; i++)
    {
        if (arr[i] == element)
        {
            for (int j = i; j < n - 1; j++)
            {
                // left shift elements
                arr[i] = arr[i + 1];
            }
        }
    }

    // decrease length
    n = n - 1;
    // Display
    printf("\nElements after deleting element %d  : ", element);
    for (i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    return 0;
}