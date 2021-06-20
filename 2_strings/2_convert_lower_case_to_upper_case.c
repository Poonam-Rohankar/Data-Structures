// Write a program to convert the lower case characters of a string into upper case

#include <stdio.h>

int main()
{
    char str[100];
    int i = 0, length;
    
    printf("Enter a string : ");
    gets(str); // get string from user

    for (i = 0; i < str[i] != '\0'; i++)
    {
        if (str[i] >= 'a' && str[i] <= 'z')
        {
            str[i] = str[i] - 32;
        }
    }

    printf("\nUppercase String is %s", str);
    return 0;
}