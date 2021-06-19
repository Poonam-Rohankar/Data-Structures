// Symmetric Matrix
#include <iostream>
using namespace std;

class Symmetric
{
private:
    int n;
    int *Mat;

public:
    Symmetric()
    {
        n = 2;
        Mat = new int[n];
    }
    Symmetric(int n)
    {
        this->n = n;
        Mat = new int[n];
    }
    ~Symmetric()
    {
        delete[] Mat;
    }

    // Members
    void Set(int i, int j, int x)
    {
        if (i >= j)
        {
            Mat[i * (i - 1) / 2 + j - 1] = x;
        }
    }

    void Display()
    {
        cout << "\nSymmetric Matrix is : " << endl;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (i >= j)
                {
                    cout << Mat[i * (i - 1) / 2 + j - 1] << "\t";
                }
                else
                {
                    cout << Mat[j * (j - 1) / 2 + i - 1] << "\t";
                }
            }
            cout << endl;
        }
    }
};

int main()
{
    int d, x;
    cout << "Enter Dimensions : ";
    cin >> d;

    // object
    Symmetric Mat(d);

    cout << endl
         << "Enter Elements : " << endl;

    for (int i = 1; i <= d; i++)
    {
        for (int j = 1; j <= d; j++)
        {
            cin >> x;
            Mat.Set(i, j, x);
        }
    }

    Mat.Display();
    Mat.~Symmetric();

    return 0;
}