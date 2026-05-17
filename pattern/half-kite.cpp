#include <iostream>

using namespace std;

// optimal way
int main()
{
    int n;
    cin >> n;

    for (int i = 1; i <= 2 * n - 1; i++)
    {
        int stars = i;
        if (i > n)
            stars = 2 * n - i;

        for (int j = 0; j < stars; j++)
        {
            cout << "*";
        }
        cout << endl;
    }

    // for (int i = 1; i <= n; i++)
    // {
    //     for (int j = 0; j < i; j++)
    //     {
    //         cout << "*";
    //     }
    //     cout << endl;
    // }

    // // --------------------------------------------
    
    // for (int i = 1; i < n; i++)
    // {
    //     for (int j = 0; j < n - i; j++)
    //     {
    //         cout << "*";
    //     }
    //     cout << endl;
    // }
}

int way2()
{
    int n;
    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            cout << "*";
        }
        cout << endl;
    }

    // --------------------------------------------
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < n - i; j++)
        {
            cout << "*";
        }
        cout << endl;
    }
}