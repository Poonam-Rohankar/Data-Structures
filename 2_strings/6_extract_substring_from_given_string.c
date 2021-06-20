// Write a program to extract a substring from the middle of a given string.

#include <stdio.h>

int main()
{
    char str[100], substr[100];
    int start, chars, i, j;

    printf("Enter String  : ");
    gets(str);

    printf("\n Enter the position from which to start the substring: ");
    scanf("%d", &start);

    printf("\nEnter the length of substring : ");
    scanf("%d", &chars);

    i = start; // starting index of main string
    j = 0;     // index of substring
    while (str[i] != '\0' && chars > 0)
    {
        substr[j] = str[i];
        i++;
        j++;
        chars--;
    }
    str[j] = '\0';
    printf("\nSubstring is : ");
    puts(substr);

    return 0;
}