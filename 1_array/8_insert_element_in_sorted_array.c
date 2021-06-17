// 8. Write a program to insert a number in an array that is already sorted in ascending order.

#include <stdio.h>

int main()
{
    int arr[20];
    int i, j, n, newElement;
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

    // take element
    printf("\nEnter element to insert : ");
    scanf("%d", &newElement);

    for (i = 0; i < n; i++)
    {
        if (arr[i] > newElement)
        {
            // shift element
            for (j = n - 1; j >= i; j--)
            {
                arr[j + 1] = arr[j];
            }
            arr[i] = newElement; // put element
            n = n + 1;           //increase length
            break;               // break the procedurwe
        }
    }

    // Display
    printf("\nElements after inserting %d  : ", newElement);
    for (i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    return 0;
}