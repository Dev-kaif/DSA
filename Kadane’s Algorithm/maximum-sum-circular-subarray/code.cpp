#include <iostream>

using namespace std;

// https://leetcode.com/problems/maximum-sum-circular-subarray/description

int main()
{
    vector<int> nums = {1, -2, 3, -2};

    int total = nums[0];

    int maxSum = nums[0];
    int maxBestEnd = nums[0];

    int minSum = nums[0];
    int minBestEnd = nums[0];

    // just calculate Max sum subarray and Min sum subarray
    for (int i = 1; i < nums.size(); i++)
    {
        total += nums[i];

        maxBestEnd = max(maxBestEnd + nums[i], nums[i]);
        maxSum = max(maxSum, maxBestEnd);

        minBestEnd = min(minBestEnd + nums[i], nums[i]);
        minSum = min(minSum, minBestEnd);
    }

    // Maximum circular subarray sum is obtained by
    // removing the minimum-sum subarray from the total sum.
    int circularMax = total - minSum;

    int res;

    // to handle the case where all elemnts are negative
    // In that case, circularMax becomes 0 by excluding
    if (maxSum < 0)
        res = maxSum;

    res = max(maxSum, circularMax);

    cout << res << endl;
    return res;
}