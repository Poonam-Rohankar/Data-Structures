/*
Write a program to input two m ¥ n matrices and then calculate the sum of their
corresponding elements and store it in a third m ¥ n matrix
*/

#include <stdio.h>
#include <stdlib.h>
int main()
{
    int row1, col1, row2, col2, i, j;
    printf("\nEnter rows and cols for matrix 1 : ");
    scanf("%d %d", &row1, &col1);
    printf("\nEnter rows and cols for matrix 2 : ");
    scanf("%d %d", &row2, &col2);

    if (row1 != row2 || col1 != col2)
    {
        printf("\nRows and Columns for both the matrices must be same !");
        exit(0);
    }
    else
    {
        int mat1[row1][col1], mat2[row2][col2], resultant[row1][col1];

        printf("\nEnter elemets for matrix 1 : \n");
        for (i = 0; i < row1; i++)
        {
            for (j = 0; j < col1; j++)
            {
                scanf("%d", &mat1[i][j]);
            }
        }

        printf("\nEnter elemets for matrix 2 : \n");
        for (i = 0; i < row2; i++)
        {
            for (j = 0; j < col2; j++)
            {
                scanf("%d", &mat2[i][j]);
            }
        }

        printf("\nMatrix 1 is :\n");
        for (i = 0; i < row1; i++)
        {
            for (j = 0; j < col1; j++)
            {
                printf("%d\t", mat1[i][j]);
            }
            printf("\n");
        }

        printf("\nMatrix 2 is :\n");
        for (i = 0; i < row2; i++)
        {
            for (j = 0; j < col2; j++)
            {
                printf("%d\t", mat2[i][j]);
            }
            printf("\n");
        }

        // calculate sum
        for (i = 0; i < row2; i++)
        {
            for (j = 0; j < col2; j++)
            {
                resultant[i][j] = mat1[i][j] + mat2[i][j];
            }
        }

        printf("\nResultant matrix is :\n");
        for (i = 0; i < row2; i++)
        {
            for (j = 0; j < col2; j++)
            {
                printf("%d\t", resultant[i][j]);
            }
            printf("\n");
        }
    }

    return 0;
}