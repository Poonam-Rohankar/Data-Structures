// 3. Write a program to print the position of the smallest number of n numbers using arrays.
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

    int smallest = arr[0], position = 0; // initially let say smallest element is at 0th position

    // find smallest element and its position
    for (i = 0; i < n; i++)
    {
        if (arr[i] < smallest)
        {
            position = i;
            smallest = arr[i];
        }
    }

    printf("\nSmallest element is %d and its on position is %d", smallest, position);

    return 0;
}