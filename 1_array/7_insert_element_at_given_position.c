// 7. Write a program to insert a number at a given position in an array.

#include <stdio.h>

int main()
{
    int arr[20];
    int i, n, newElement, position;
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

    // take position
    printf("\nEnter position for %d : ", newElement);
    scanf("%d", &position);

    // check for space availabe
    if (position >= 20)
    {
        printf("\nInsufficient Space !");
    }
    else if (position < 0)
    {
        printf("\nInvalid Position !");
    }
    else
    {
        // right shift element to make space for new element
        for (i = n - 1; i >= position; i++)
        {
            arr[i + 1] = arr[i];
        }

        arr[position] = newElement; //put element
        n = n + 1;                  //increase length
    }

    // Display
    printf("\nElements after inserting %d  : ", newElement);
    for (i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    return 0;
}