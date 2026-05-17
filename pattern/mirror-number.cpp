#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        for (int number = 1; number <= i; number++)
        {
            cout << number;
        }
        for (int space = 1; space <= 2 * (n - i); space++)
        {
            cout << " ";
        }

        for (int number = i; number > 0; number--)
        {
            cout << number;
        }

        cout << endl;
    }
}