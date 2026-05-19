
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// O(n log n)
int main()
{
    vector<int> arr = {3, 2, 4};

    sort(arr.begin(), arr.end());

    int target = 6;
    int i = 0;
    int j = arr.size() - 1;

    while (i < j)
    {
        int sum = arr[i] + arr[j];

        if (sum == target)
        {
            cout << "[" << i << ", " << j << "]" << endl;
            break;
        }

        if (sum > target)
        {
            j--;
            continue;
        }

        if (sum < target)
        {
            i++;
            continue;
        }
    }

}