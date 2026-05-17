#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        for (int space = 0; space < n - i - 1; space++)
        {
            cout << " ";
        }

        for (int star = 0; star < (2 * i) + 1; star++)
        {
            cout << "*";
        }

        for (int space = 0; space < n - i - 1; space++)
        {
            cout << " ";
        }
        cout << endl;
    }
}