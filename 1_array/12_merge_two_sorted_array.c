// 12. Write a program to merge two sorted arrays.

#include <stdio.h>

int main()
{
    int n1, n2, totalElements, i, first_index = 0, second_index = 0, new_index = 0;

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

    // merge by comparing elements
    while (first_index < n1 && second_index < n2)
    {
        if (arr1[first_index] < arr2[second_index])
        {
            arr3[new_index] = arr1[first_index];
            first_index++;
        }
        else
        {
            arr3[new_index] = arr2[second_index];
            second_index++;
        }
        new_index++;
    }

    // now after merging if elements of second array are left
    if (first_index == n1 && second_index != n2)
    {
        while (second_index < n2)
        {
            arr3[new_index] = arr2[second_index];
            second_index++; // increment index of 2nd array
            new_index++;    // increment index of new array
        }
    }
    // if 2nd array elements are over but the first array elements are left
    else if (second_index == n2 && first_index != n1)
    {
        while (first_index < n1)
        {
            arr3[new_index] = arr1[first_index];
            first_index++; // increment index of 2nd array
            new_index++;   // increment index of new array
        }
    }

    // display after merge
    printf("\n Final array after merging: ");
    for (i = 0; i < totalElements; i++)
    {
        printf("%d ", arr3[i]);
    }

    return 0;
}