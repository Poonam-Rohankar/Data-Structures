// Write a program to insert a string in the main text.
#include <stdio.h>

int main()
{
    char text[100], str[50], ins_text[100];
    int i = 0, j = 0, k = 0, pos;

    printf("Enter the main text : ");
    gets(text);

    printf("Enter string to be inserted : ");
    gets(str);

    printf("Enter the position at which string has to be inserted : ");
    scanf("%d", &pos);

    while (text[i] != '\0')
    {
        if (i == pos)
        {
            while (str[k] != '\0')
            {
                ins_text[j] = str[k];
                j++;
                k++;
            }
        }
        else // insert before and aftter string
        {
            ins_text[j] = text[i];
            j++;
        }
        i++;
    }

    ins_text[j] = -'\0'; // terminate string
    printf("\nResultant string is : ");
    puts(ins_text);

    return 0;
}