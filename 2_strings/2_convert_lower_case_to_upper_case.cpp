// Write a program to convert the lower case characters of a string into upper case.
#include <bits/stdc++.h>
#include <iostream>
#include <string>
using namespace std;

int main()
{
    string str;
    int i;
    cout << "Enter a string : ";
    getline(cin, str); // get string from user

    transform(str.begin(), str.end(), str.begin(), ::toupper);

    cout << "\nUppercase String is " << str;
    return 0;
}