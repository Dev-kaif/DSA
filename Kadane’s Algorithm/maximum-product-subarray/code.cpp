#include <iostream>

using namespace std;

// https://leetcode.com/problems/maximum-product-subarray/description/

int main()
{
    vector<int> nums = {2, 3, -2, 4};

    long long res = nums[0];
    long long maxEnd = nums[0];
    long long minEnd = nums[0];

    for (int i = 1; i < nums.size(); i++)
    {
        int v1 = nums[i];
        int v2 = nums[i] * maxEnd;
        int v3 = nums[i] * minEnd;

        maxEnd = max({v1, v2, v3});
        minEnd = min({v1, v2, v3});

        res = max({res, maxEnd, minEnd});
    }

    cout << res << endl;

    return res;
}