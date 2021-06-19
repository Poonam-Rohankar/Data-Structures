// Write a program to find the length of a string.

#include <stdio.h>

int main()
{
    char str[100], i = 0, length;
    printf("Enter a string : ");
    gets(str); // get string from user

    while (str[i] != '\0')
        i++;

    length = i;

    printf("\nThe Length of the string is : %d", length);
    return 0;
}