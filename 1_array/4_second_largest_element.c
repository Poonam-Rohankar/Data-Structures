// 4. Write a program to find the second largest of n numbers using an array.
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

    int largest = arr[0]; // initially let say largest element is arr[0]

    // find largest of all
    for (i = 0; i < n; i++)
    {
        if (arr[i] > largest)
        {
            largest = arr[i];
        }
    }

    int second_largest = arr[1]; // initially let say 2nd element is largest

    // find second largest
    for (i = 0; i < n; i++)
    {
        // exclude largest
        if (arr[i] != largest)
        {
            if (arr[i] > second_largest)
            {
                second_largest = arr[i];
            }
        }
    }

    printf("\nLargest element is %d", largest);
    printf("\nSecond largest element is %d", second_largest);
    return 0;
}