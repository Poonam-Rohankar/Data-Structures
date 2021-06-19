// Lower Triangular Matrix

#include <iostream>
using namespace std;

class LowerTriangular
{
private:
    int n;
    int *Mat;

public:
    LowerTriangular()
    {
        n = 2;
        Mat = new int[n];
    }
    LowerTriangular(int n)
    {
        this->n = n;
        Mat = new int[n];
    }
    ~LowerTriangular()
    {
        delete[] Mat;
    }

    void Set(int i, int j, int x);
    void Display();
};

void LowerTriangular::Set(int i, int j, int x)
{
    if (i >= j)
    {
        Mat[i * (i - 1) / 2 + j - 1] = x;
    }
}

void LowerTriangular::Display()
{
    cout << endl
         << "Lower Traingular Matrix is : " << endl;

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
                cout << "0\t";
            }
        }
        cout << endl;
    }
}

int main()
{
    int d, x;
    cout << "Enter Dimensions : ";
    cin >> d;

    // object
    LowerTriangular Mat(d);

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
    Mat.~LowerTriangular();

    return 0;
}