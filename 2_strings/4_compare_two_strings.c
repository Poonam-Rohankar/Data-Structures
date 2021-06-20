// Write a program to compare two strings.

#include <stdio.h>
#include <string.h>
int main()
{
    char str1[100], str2[100];
    int len1 = 0, len2 = 0, same = 0;
    int i = 0;

    printf("Enter string 1 : ");
    gets(str1);

    printf("Enter string 2 : ");
    gets(str2);

    len1 = strlen(str1); // length of string 1
    len2 = strlen(str2); // length of string 2

    if (len1 == len2)
    { // check for similarity

        while (i < len1)
        {
            if (str1[i] == str2[i])
            {
                i++;
            }
            else
                break;
        }
        if (i == len1)
        {
            same = 1;
            printf("\nBoth the strings are equal");
        }
    }
    else if (len1 != len2)
    {
        printf("\nBoth the strings are not equal");
    }

    if (same == 0)
    {
        if (str1[i] > str2[i])
        {
            printf("\nString 1 is greater than string 2 !");
        }
        else if (str1[i] < str2[i])
        {
            printf("\nString 2 is greater than string 1 !");
        }
    }

    return 0;
}