// 11. Write a program to merge two unsorted arrays.

#include <stdio.h>

int main()
{
    int n1, n2, totalElements, i, index = 0;

    // first array ------------
    printf("Enter size of  1st array : ");
    scanf("%d", &n1);

    // initialize array 1 of size n1
    int arr1[n1];

    // input array 1;
    printf("\nEnter %d elements for 1st array\n", n1);
    for (i = 0; i < n1; i++)
    {
        scanf("%d", &arr1[i]);
    }
    // ------------------

    // second array -----------
    printf("Enter size of  2nd array : ");
    scanf("%d", &n2);

    // initialize array 1 of size n1
    int arr2[n2];

    // input array 1;
    printf("\nEnter %d elements for 2st array\n", n2);
    for (i = 0; i < n2; i++)
    {
        scanf("%d", &arr2[i]);
    }

    // display
    printf("\n First array : ");
    for (i = 0; i < n1; i++)
    {
        printf("%d ", arr1[i]);
    }

    printf("\n Second array : ");
    for (i = 0; i < n2; i++)
    {
        printf("%d ", arr2[i]);
    }

    // total no of elements
    totalElements = n1 + n2;

    // declare new array of new size
    int arr3[totalElements];

    // copy array 1 into new array
    for (i = 0; i < n1; i++)
    {
        arr3[index] = arr1[i];
        index++;
    }

    // append arry 2 into new array
    for (i = 0; i < n2; i++)
    {
        arr3[index] = arr2[i];
        index++;
    }

    // display after merge
    printf("\n Final array after merging: ");
    for (i = 0; i < totalElements; i++)
    {
        printf("%d ", arr3[i]);
    }

    return 0;
}