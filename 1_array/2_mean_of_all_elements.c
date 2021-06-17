// 2. Write a program to find the mean of n numbers using arrays.

#include <stdio.h>

int main()
{
    int i, n, sum = 0;
    float mean = 0.0;
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

    //Sum of all elements
    for (i = 0; i < n; i++)
    {
        sum += arr[i];
    }

    // Mean of all elements = sum of all elements divide by number of elements
    mean = (float)sum / n;
    printf("\nMean of %d elements is %.2f", n, mean);
    return 0;
}