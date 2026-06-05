#include <iostream>

using namespace std;

// https://leetcode.com/problems/minimum-size-subarray-sum/description/

int main()
{
    vector<int> nums = {2, 3, 1, 2, 4, 3};
    int target = 7;
    int n = nums.size();

    int low = 0;
    int high = 0;

    int sum = 0;
    int res = INT_MAX;

    while (high < n)
    {
        sum += nums[high];

        while (sum >= target)
        {
            int len = high - low + 1;
            res = min(res, len);
            sum -= nums[low];
            low++;
        }

        high++;
    }

    // return res == INT_MAX ? 0 : res;

    cout << res << endl;
}