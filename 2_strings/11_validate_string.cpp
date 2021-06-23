// check for string containing alphabes and numebrs

#include <iostream>
#include <string>
using namespace std;

int valid(string str)
{

    for (int i = 0; str[i] != '\0'; i++)
    {
        if (!(str[i] >= 65 && str[i] <= 90) && !(str[i] >= 97 && str[i] <= 122) && !(str[i] >= 48 && str[i] <= 57))
        {
            return 0;
        }
    }
    return 1;
}

int main()
{
    string str;
    cout << "Enter a string : ";
    cin >> str;

    if (valid(str) == 1)
    {
        cout << endl
             << "Valid";
    }
    else
    {
        cout << "Invalid";
    }
    return 0;
}