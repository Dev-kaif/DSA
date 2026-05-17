#include <iostream>

using namespace std;

// 1
// 0 1
// 1 0 1
// 0 1 0 1

int main()
{
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int start = 0;

        if (i % 2 == 0)
            start = 1;

        for (int j = 0; j < i + 1; j++)
        {
            cout << start << " ";
            start = 1 - start;
        }
        cout << endl;
    }
}