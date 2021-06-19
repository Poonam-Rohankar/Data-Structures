// Diagonal
#include <iostream>
using namespace std;

class Diagonal
{
private:
    int *Mat;
    int n;

public:
    Diagonal() // default constructor
    {
        n = 2;
        Mat = new int[n];
    }

    Diagonal(int n)
    {
        this->n = n;
        Mat = new int[n];
    }

    ~Diagonal() // deconstructor
    {
        delete[] Mat;
    }

    void Set(int i, int j, int x);
    int Get(int i, int j);
    void Display();
};

void Diagonal::Set(int i, int j, int x)
{
    if (i == j)
    {
        Mat[i] = x;
    }
}

int Diagonal::Get(int i, int j)
{
    if (i == j)
    {
        return Mat[i - 1];
    }
    else
    {
        return 0;
    }
}

void Diagonal::Display()
{
    cout << endl
         << "Diagonal Matrix is :" << endl;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == j)
            {
                cout << Mat[i] << "\t";
            }
            else
            {
                cout << "0\t";
            }
        }
        cout << endl;
    }
}

// Main
int main()
{
    int d, x;
    cout << "Enter Dimensions : ";
    cin >> d;

    // object
    Diagonal Mat(d);

    cout << endl
         << "Enter Elements : " << endl;

    for (int i = 0; i < d; i++)
    {
        for (int j = 0; j < d; j++)
        {
            cin >> x;
            Mat.Set(i, j, x);
        }
    }

    Mat.Display();
    Mat.~Diagonal();

    return 0;
}