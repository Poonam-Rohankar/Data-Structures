// 5. Write a program to enter n number of digits. Form a number using these digits.
#include <stdio.h>
#include <math.h>
int main()
{
    int number = 0, numofdigits, i;
    printf("\n Enter the number of digits : ");
    scanf("%d", &numofdigits);

    int digit[numofdigits];
    // Read
    for (i = 0; i < numofdigits; i++)
    {
        printf("\n Enter the digit at position %d", i + 1);
        scanf("%d", &digit[i]);
    }

    i = 0;
    // Form Number
    while (i < numofdigits)
    {
        number = number + digit[i] * pow(10, i);
        i++;
    }
    printf("\n The number is : %d", number);
    return 0;
}