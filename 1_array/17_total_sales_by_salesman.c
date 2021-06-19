/* 17. In a small company there are five salesmen. Each salesman is supposed to sell three
products. Write a program using a 2D array to print (i) the total sales by each salesman
and (ii) total sales of each item. */

#include <stdio.h>

int main()
{
    int sales[5][3], i, j, total_sales = 0;

    // Enter the sales data of all three items for each elmployee
    printf("Enter the sales data of all three items for each elmployee\n");
    for (i = 0; i < 5; i++)
    {
        printf("Enter the sales for 3 items solid by salesman %d : ", i + 1);
        // ----
        for (j = 0; j < 3; j++)
        {
            scanf("%d", &sales[i][j]);
        }
    }

    // Total Sales by each employee
    for (i = 0; i < 5; i++)
    {
        total_sales = 0;
        for (j = 0; j < 3; j++) // sales for each elmploye
        {
            total_sales += sales[i][j]; // row wise sum
        }
        printf("\nTotal sales By Salesman %d : %d", i + 1, total_sales);
    }

    // total sales of each item
    for (i = 0; i < 3; i++)
    {
        total_sales = 0;
        for (j = 0; j < 5; j++)
        {
            total_sales += sales[j][i]; // column wise sum
        }
        printf("\nTotal sales of Item  %d : %d", i + 1, total_sales);
    }
    return 0;
}