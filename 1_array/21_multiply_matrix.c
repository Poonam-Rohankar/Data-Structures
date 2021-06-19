// Write a program to multiply two m ¥ n matrices.

#include <stdio.h>
#include <stdlib.h>
int main()
{
    int row1, col1, row2, col2, i, j, k;
    printf("\nEnter rows and cols for matrix 1 : ");
    scanf("%d %d", &row1, &col1);
    printf("\nEnter rows and cols for matrix 2 : ");
    scanf("%d %d", &row2, &col2);

    if (col1 != row2)
    {
        printf("\nNo of columns of matrix 1 must be equal to no of rows of matrix 2 !");
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

        // calculate multiplication
        for (i = 0; i < row1; i++)
        {
            for (j = 0; j < col2; j++)
            {
                resultant[i][j] = 0;
                for (k = 0; k < col2; k++)
                    resultant[i][j] += mat1[i][k] * mat2[k][j];
            }
        }

        printf("\nResultant matrix is :\n");
        for (i = 0; i < row1; i++)
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