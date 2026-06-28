#include <iostream>

using namespace std;

// https://leetcode.com/problems/maximum-subarray/description/
int main()
{
    vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};

    int res = nums[0];
    int bestEnd = nums[0];

    for (int i = 1; i < nums.size(); i++)
    {
        int v1 = nums[i];
        int v2 = nums[i] + bestEnd;

        bestEnd = max(v1, v2);
        res = max(res, bestEnd);
    }

    return res;
}