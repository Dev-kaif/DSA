#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    vector<int> arr = {0, 1, 0, 1, 0, 0, 1, 1, 1, 0};
    int low = 0, mid = 0, high = arr.size() - 1;

    while (mid <= high)
    {
        int value = arr[mid];

        if (value == 0)
        {
            swap(arr[mid], arr[low]);
            low++;
            mid++;
        }
        else
        {
            swap(arr[mid], arr[high]);
            high--;
        }
    }

    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}