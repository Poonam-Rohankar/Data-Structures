// 13. Write a program to read an array of n numbers and then find the smallest number.

#include <stdio.h>

// function to read array
void readArray(int arr[], int n);

// fubnction to display elements
void display(int arr[], int n);

// function to find and return smallest number
int smallestNumber(int arr[], int n);

int main()
{
    int n, smallest_num;
    printf("Enter size of array : ");
    scanf("%d", &n);

    int arr[n];
    readArray(arr, n);
    display(arr, n);

    smallest_num = smallestNumber(arr, n);
    printf("\nSmallest element is %d", smallest_num);

    return 0;
}

void readArray(int arr[], int n)
{
    int i;
    printf("\nEnter %d elements :\n", n);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
}

void display(int arr[], int n)
{
    int i;
    printf("Array Elements are : ");
    for (i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
}

int smallestNumber(int arr[], int n)
{
    int i, smallest = arr[0]; // initially lets consider smallest number is arr[0]
    for (i = 0; i < n; i++)
    {
        if (arr[i] < smallest)
        {
            smallest = arr[i];
        }
    }

    return smallest; // return smallest number
}