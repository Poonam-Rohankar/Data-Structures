// Write a program to find the length of a string.

#include <iostream>
#include <string>
using namespace std;

int main()
{
    string str;
    int length;
    cout << "Enter a string : ";
    getline(cin, str);

    // length
    length = str.length();
    cout << endl
         << "Length of string is : " << length;

    return 0;
}