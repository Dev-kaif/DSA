#include <iostream>

using namespace std;

// https://www.geeksforgeeks.org/problems/max-sum-subarray-of-size-k5313/1

int main()
{
    vector<int> arr = {100, 200, 300, 400};
    int k = 2;

    int n = arr.size();

    int low = 0;
    int high = 1;

    int sum = 0;
    int res = 0;

    for (int i = 0; i <= high; i++)
    {
        sum += arr[i];
    }

    while (high < n)
    {
        res = max(sum, res);

        low++;
        high++;

        if (high == n)
        {
            break;
        }

        sum -= arr[low - 1];
        sum += arr[high];
    }

    return res;

    cout << res << endl;
}