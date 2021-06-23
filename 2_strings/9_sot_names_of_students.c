// Write a program to sort the names of students.

#include <stdio.h>
#include <string.h>

int main()
{
    char names[5], temp[10];
    int i, j, n;

    printf("Enter number  of students : ");
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        printf("\nEnter name of student %d : ", i + 1);
        gets(names[i]);
    }

    // sort names swapping
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            if (strcmp(names[j], names[j + 1]) > 0)
            {
                strcpy(temp, names[j]);
                strcpy(names[j], names[j + 1]);
                strcpy(names[j + 1], temp);
            }
        }
    }
    printf("\n Names of studens after sorting are : \n");
    for (i = 0; i < n; i++)
    {
        puts(names[i]);
    }

    return 0;
}