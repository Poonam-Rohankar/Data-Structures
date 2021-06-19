// Upper Triangular Matrix

#include <iostream>
using namespace std;

class UpperTriangular
{
private:
    int n;
    int *Mat;

public:
    UpperTriangular()
    {
        n = 2;
        Mat = new int[n];
    }
    UpperTriangular(int n)
    {
        this->n = n;
        Mat = new int[n];
    }
    ~UpperTriangular()
    {
        delete[] Mat;
    }

    void Set(int i, int j, int x);
    void Display();
};

void UpperTriangular::Set(int i, int j, int x)
{
    if (i <= j)
    {
        Mat[j * (j - 1) / 2 + i - 1] = x;
    }
}

void UpperTriangular::Display()
{
    cout << endl
         << "Lower Traingular Matrix is : " << endl;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (i <= j)
            {
                cout << Mat[j * (j - 1) / 2 + i - 1] << "\t";
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
    UpperTriangular Mat(d);

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
    Mat.~UpperTriangular();

    return 0;
}