#include <iostream>
#include <string>
using namespace std;

int main()
{
    string str1, str2;
    int i, j;
    cout << "Enter striong 1 : ";
    cin >> str1;

    cout << endl
         << "Enter string 2 : ";
    cin >> str2;

    for (i = 0, j = 0; str1[i] != '\0' && str2[j] != '\0'; i++, j++)
    {
        if (str1[i] != str2[j])
        {
            break;
        }
    }

    if (str1[i] == str2[j])
    {
        cout << endl
             << "Matched";
    }
    else if (str1[i] < str2[j])
    {
        cout << endl
             << "String 1 is smaller than String 2";
    }
    else if (str1[i] > str2[j])
    {
        cout << endl
             << "String 2 is smaller than String 1";
    }

    return 0;
}