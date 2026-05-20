#include <iostream>
#include <vector>

using namespace std;

// O(n)
int main()
{
    vector<int> arr = {-4, -1, 0, 3, 10};

    vector<int> result(arr.size());

    int resultEndIndex = result.size() - 1;

    int start = 0;
    int end = arr.size() - 1;

    while (start <= end)
    {
        if (abs(arr[start]) >= abs(arr[end]))
        {
            result[resultEndIndex] = arr[start] * arr[start];
            ++start;
        }
        else
        {
            result[resultEndIndex] = arr[end] * arr[end];
            --end;
        }
        --resultEndIndex;
    }

    for (int i = 0; i < arr.size(); i++)
    {
        cout << result[i] << " ";
    }
    cout << endl;
}
