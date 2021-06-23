// Count number of words

#include <iostream>
#include <string>
using namespace std;

int main()
{
    string text;
    int words = 1; 
    cout << "Enter a string : ";
    getline(cin, text);

    for (int i = 0; text[i] != '\0'; i++)
    {
        if (text[i] == ' ' && text[i - 1] != ' ')
        {
            words++;
        }
    }

    cout << endl
         << "Total no of words are : " << words;
    return 0;
}