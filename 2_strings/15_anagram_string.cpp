#include <iostream>
using namespace std;

int main()
{
    string str1, str2;
    int H[26] = {0}, i;
    cout << "Enter string 1 : ";
    cin >> str1;

    cout << "Enter string 2 : ";
    cin >> str2;

    for (i = 0; str1[i] != '\0'; i++)
    {
        H[str1[i] - 97] += 1;
    }

    for (i = 0; str2[i] != '\0'; i++)
    {
        H[str2[i] - 97] -= 1;

        if (H[str2[i] - 97] < 0)
        {
            cout << "Not Anagram !";
            break;
        }
    }

    // if string 2 reaches end
    if (str2[i] == '\0')
    {
        cout << "Anagram";
    }

    return 0;
}