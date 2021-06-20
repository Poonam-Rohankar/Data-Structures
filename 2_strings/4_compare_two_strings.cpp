// Write a program to compare two strings.

#include <iostream>
using namespace std;
int main()
{
    string str1, str2;
    int len1 = 0, len2 = 0, same = 0;
    int i = 0;

    cout << "Enter string 1 : ";
    getline(cin, str1);

    cout << "Enter string 2 : ";
    getline(cin, str2);

    len1 = str1.length(); // length of string 1
    len2 = str2.length(); // length of string 2

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
            cout << "\nBoth the strings are equal" << endl;
        }
    }
    else if (len1 != len2)
    {
        cout << "\nBoth the strings are not equal" << endl;
    }

    if (same == 0)
    {
        if (str1[i] > str2[i])
        {
            cout << "\nString 1 is greater than string 2 !" << endl;
        }
        else if (str1[i] < str2[i])
        {
            cout << "\nString 2 is greater than string 1 !" << endl;
        }
    }

    return 0;
}