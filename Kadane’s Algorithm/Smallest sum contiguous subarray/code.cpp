#include <iostream>

using namespace std;

// https://www.geeksforgeeks.org/problems/smallest-sum-contiguous-subarray/1
int main()
{
    vector<int> nums = {3, -4, 2, -3, -1, 7, -5};

    int res = nums[0];
    int bestEnd = nums[0];

    for (int i = 1; i < nums.size(); i++)
    {
        int v1 = nums[i];
        int v2 = nums[i] + bestEnd;

        bestEnd = min(v1, v2);
        res = min(res, bestEnd);
    }

    cout << res << endl;

    return res;
}