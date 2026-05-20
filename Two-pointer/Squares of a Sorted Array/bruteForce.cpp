#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

// O(n log n)
int main()
{
    vector<int> arr = {-4, -1, 0, 3, 10};

    for (int i = 0; i < arr.size(); i++)
    {
        arr[i] = arr[i] * arr[i];
    }

    sort(arr.begin(), arr.end());

    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
}