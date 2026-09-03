#include <iostream>

using namespace std;

// https://leetcode.com/problems/house-robber/description/

class Solution
{
    vector<vector<int>> dp;

    int solve(vector<int> &nums, bool canRob, int index)
    {

        if (index == nums.size())
        {
            return 0;
        }

        if (dp[index][canRob] != -1)
        {
            return dp[index][canRob];
        }

        // Cannot rob this house, so skip it.
        if (!canRob)
        {
            int best = solve(nums, true, index + 1);

            dp[index][canRob] = best;
            return best;
        }

        // Rob the current house.
        int robCurrent = nums[index] + solve(nums, false, index + 1);

        // Skip the current house.
        int skipCurrent = solve(nums, true, index + 1);

        int best = max(robCurrent, skipCurrent);

        dp[index][canRob] = best;

        return best;
    }

public:
    int rob(vector<int> &nums)
    {

        int n = nums.size();

        dp = vector<vector<int>>(n, vector<int>(2, -1));

        int skipFirst = solve(nums, false, 0);
        int robFirst = solve(nums, true, 0);

        return max(skipFirst, robFirst);
    }
};
