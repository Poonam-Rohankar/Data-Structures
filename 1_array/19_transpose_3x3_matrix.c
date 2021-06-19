// Write a program to transpose a 3¥3 matrix

#include <stdio.h>

int main()
{
    int matrix[3][3], transpose[3][3], i, j;

    printf("Enter elements of the matrix :\n");
    for (i = 0; i < 3; i++)
    {
        printf("Enter elements for row %d : ", i + 1);
        for (j = 0; j < 3; j++)
        {
            scanf("%d", &matrix[i][j]);
        }
    }

    // make transpose
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            transpose[i][j] = matrix[j][i];
        }
    }

    printf("\nTranspose of matrix is :\n");
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            printf("%d\t", transpose[i][j]);
        }
        printf("\n");
    }

    return 0;
}