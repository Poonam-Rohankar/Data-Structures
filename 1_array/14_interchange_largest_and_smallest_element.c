// 14. Write a program to interchange the largest and the smallest number in an array.

#include <stdio.h>

// function to read array
void readArray(int arr[], int n);

// fubnction to display elements
void display(int arr[], int n);

// find position of smallest element
int position_smallest(int arr[], int n);

// find position of largest element
int position_largest(int arr[], int n);

// interchange elements
void interchange(int arr[], int pos_smallest, int pos_largest);

int main()
{
    int n, pos_smallest, pos_largest;
    printf("Enter size of array : ");
    scanf("%d", &n);

    // declare array of size n
    int arr[n];

    readArray(arr, n);
    display(arr, n);

    pos_smallest = position_smallest(arr, n);
    pos_largest = position_largest(arr, n);

    interchange(arr, pos_smallest, pos_largest);
    printf("\nArray after interchanging elements %d and %d \n", arr[pos_smallest], arr[pos_largest]);
    display(arr, n);

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

int position_smallest(int arr[], int n)
{
    int i, position = 0, smallest = arr[0];
    for (i = 1; i < n; i++)
    {
        if (arr[i] < smallest)
        {
            smallest = arr[i];
            position = i;
        }
    }
    return position;
}

int position_largest(int arr[], int n)
{
    int i, position = 0, largest = arr[0];
    for (i = 1; i < n; i++)
    {
        if (arr[i] > largest)
        {
            largest = arr[i];
            position = i;
        }
    }
    return position;
}

void interchange(int arr[], int pos_smallest, int pos_largest)
{
    int temp;
    temp = arr[pos_smallest];
    arr[pos_smallest] = arr[pos_largest];
    arr[pos_largest] = temp;
}
