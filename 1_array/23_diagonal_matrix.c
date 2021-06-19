// Diagonal matrix

#include <stdio.h>
#include <stdlib.h>

struct Matrix
{
    int n;
    int M[n];
};

void Set(struct Matrix *Mat, int i, int j, int x)
{
    if (i == j)
    {
        Mat->M[i - 1] = x;
    }
}

int Get(struct Matrix Mat, int i, int j)
{
    if (i == j)
    {
        return Mat.M[i - 1];
    }
    else
        return 0;
}

void display(struct Matrix Mat)
{
    int i, j;
    printf("\nDiagonal Matrix is :\n");
    for (i = 0; i < Mat.n; i++)
    {
        for (j = 0; j < Mat.n; j++)
        {
            if (i == j)
            {
                printf("%d\t", Mat.M[i]);
            }
            else
            {
                printf("0\t");
            }
        }
        printf("\n");
    }
}

int main()
{
    struct Matrix Mat;
    Mat.n = 4;

    Set(&Mat, 1, 1, 1);
    Set(&Mat, 2, 2, 2);
    Set(&Mat, 3, 3, 3);
    Set(&Mat, 4, 4, 4);

    display(Mat);
    return 0;
}