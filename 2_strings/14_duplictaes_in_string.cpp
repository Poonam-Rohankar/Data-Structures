#include <iostream>
using namespace std;

int main()
{
    string A;
    int H[26] = {0}, i;

    cout << "Enter a string : ";
    cin >> A;

    for (i = 0; A[i] != '\0'; i++)
    { //Subtracting 97 from index to reach hash index
        H[A[i] - 65] += 1;
    }

    for (i = 0; i < 26; i++)
    {
        if (H[i] > 1)
        {
            printf("Repeated Character is : %c for %d times \n", i + 65, H[i]);
        }
    }
    return 0;
}