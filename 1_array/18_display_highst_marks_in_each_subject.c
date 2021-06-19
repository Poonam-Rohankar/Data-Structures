/* 
Write a program to read a 2D array marks which stores the marks of five students in three
subjects. Write a program to display the highest marks in each subject.
*/

#include <stdio.h>

int main()
{
    int marks[5][3], i, j, max_marks;

    printf("Enter Marks for each student :\n");
    for (i = 0; i < 5; i++)
    {
        printf("Enter marks for student %d : ", i + 1);
        for (j = 0; j < 3; j++)
        {
            scanf("%d", &marks[i][j]);
        }
    }

    // calculate & display max marks
    for (j = 0; j < 3; j++)
    {
        max_marks = -999;
        for (i = 0; i < 5; i++) // row wise comparison
        {
            if (marks[i][j] > max_marks)
            {
                max_marks = marks[i][j];
            }
        }
        printf("\nMaximum marks obtained in subject %d : %d", j + 1, max_marks);
    }
    
    return 0;
}