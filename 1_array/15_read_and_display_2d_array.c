// 16. Write a program read to print the elements of a 2D array.

#include <stdio.h>
int main()
{
    int i, j, rows, cols;
    printf("Enter no of rowss and colsumns : ");
    scanf("%d %d", &rows, &cols);

    int arr[rows][cols];

    printf("\nEnter elements for %d x %d array :\n");
    for (i = 0; i < rows; i++)
    {
        for (j = 0; j < cols; j++)
            scanf("%d", &arr[i][j]);
    }

    printf("\nEnterd 2D array is : ");
    for (i = 0; i < rows; i++)
    {
        for (j = 0; j < cols; j++)
        {
            printf("%d\t", arr[i][j]);
        }
        printf("\n");
    }

    return 0;
}