// Write a program to reverse a given string.

#include <stdio.h>
#include <string.h>
int main()
{
    char str[100];
    int i = 0, j;

    printf("Enter a string : ");
    gets(str);

    j = strlen(str) - 1;

    while (i < j)
    {
        char temp = str[j];
        str[j] = str[i];
        str[i] = temp;
        i++;
        j--;
    }

    printf("\nReverse string is : ");
    puts(str);
    return 0;
}