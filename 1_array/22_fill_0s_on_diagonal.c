/*
Write a program to fill a square matrix with value zero on the diagonals, 1 on the upper
right triangle, and –1 on the lower left triangle.
*/

#include <stdio.h>

int main()
{
    int n = 5, matrix[n][n], i, j;

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (i == j)
            {
                matrix[i][j] = 0;
            }
            else if (i > j)
            {
                matrix[i][j] = -1;
            }
            else if (i < j)
            {
                matrix[i][j] = 1;
            }
        }
    }

    printf("\nResultant matrix is : \n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            printf("%d\t", matrix[i][j]);
        }
        printf("\n");
    }

    return 0;
}