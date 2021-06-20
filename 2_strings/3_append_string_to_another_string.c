// Write a program to append a string to another string.

#include <stdio.h>

int main()
{
    char str1[100], str2[100];
    int length = 0;

    printf("Enter String 1 : ");
    gets(str1);

    printf("\nEnter String 2 : ");
    gets(str2);

    // length of 1nd string
    for (int i = 0; str1[i] != '\0'; i++)
    {
        length++;
    }

    // append 2nd string
    for (int i = 0; str2[i] != '\0'; i++)
    {
        str1[length] = str2[i];
        length++;
    }

    printf("\nResultant string is %s", str1);
    return 0;
}