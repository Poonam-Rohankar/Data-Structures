// Write a program to reverse a given string.

#include <iostream>
using namespace std;

int main()
{
    string str;
    int i = 0, j;

    cout << "Enter a string : ";
    getline(cin, str);

    j = str.length() - 1;

    while (i < j)
    {
        char temp = str[j];
        str[j] = str[i];
        str[i] = temp;
        i++;
        j--;
    }

    cout << "\nReverse string is : " << str;
    return 0;
}