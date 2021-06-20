// Write a program to append a string to another string.

#include <iostream>
using namespace std;

int main()
{
    string str1, str2, str3;

    cout << "Enter String 1 : ";
    getline(cin, str1);

    cout << endl
         << "\nEnter String 2 : ";
    getline(cin, str2);

    // Concatenate string
    str3 = str1 + str2;

    cout << endl
         << "Resultant string is " << str3;
    return 0;
}