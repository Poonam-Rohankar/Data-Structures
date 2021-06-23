#include <iostream>
using namespace std;
int main()
{
    string str;
    int i, j;

    cout << "Enter a string to check palindrome : ";
    cin >> str;

    for (i = 0, j = str.length() - 1; i < j; i++, j--)
    {
        if (str[i] != str[j])
        {
            break;
        }
    }
    if (str[i] == str[j])
    {
        cout << endl
             << "Palindrome";
    }
    else
    {
        cout << endl
             << "Not Palindrome";
    }
    return 0;
}