// 9. Write a program to delete a number from a given location in an array.

#include <stdio.h>

int main()
{
    int arr[20];
    int i, n, position;
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

    // input location to delete
    printf("\nEnter position to delete element from : ");
    scanf("%d", &position);

    if (position < 0)
    {
        printf("\nInvalid Position !");
    }
    else
    {
        for (i = position; i < n - 1; i++)
        {
            // left shift elements
            arr[i] = arr[i + 1];
        }

        // decrease length by 1
        n = n - 1;
    }

    // Display
    printf("\nElements after deleting element from %d locaion : ", position);
    for (i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    return 0;
}