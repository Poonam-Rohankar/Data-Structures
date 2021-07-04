#include <stdio.h>
#include <stdlib.h>

void insert(int H[], int n) // n is index
{
    int i = n, temp;
    temp = H[n];

    while (i > 1 && temp > H[i / 2])
    {
        H[i] = H[i / 2];
        i = i / 2;
    }
    H[i] = temp;
}

int Delete(int H[], int n)
{
    int x, i, j;

    int temp;

    x = H[1]; // take out root element

    H[1] = H[n]; // replace root element with last element

    i = 1; // parent

    j = i * 2; // left  child of parent

    while (j < n - 1)
    {
        if (H[j + 1] > H[j])
            j = j + 1;

        if (H[i] < H[j])
        {
            temp = H[i];
            H[i] = H[j];
            H[j] = temp;

            i = j;
            j = 2 * j;
        }
        else
            break;
    }

    return x;
}

int main()
{
    int H[] = {0, 1, 2, 3, 445, 78, 23, 54};

    for (int i = 2; i <= 7; i++)
    {
        insert(H, i);
    }

    printf("\nHeap is :- ");
    for (int i = 1; i <= 7; i++)
    {
        printf("\t%d", H[i]);
    }

    Delete(H, 7);

    printf("\nHeap is :- ");
    for (int i = 1; i <= 7; i++)
    {
        printf("\t%d", H[i]);
    }

    Delete(H, 6);

    printf("\nHeap is :- ");
    for (int i = 1; i <= 7; i++)
    {
        printf("\t%d", H[i]);
    }

    return 0;
}