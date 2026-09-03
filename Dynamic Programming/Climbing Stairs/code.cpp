#include <iostream>

using namespace std;

// https://leetcode.com/problems/climbing-stairs/

class Solution
{
    unordered_map<int, int> dp;

public:
    int climbStairs(int n)
    {
        if (n <= 1)
            return 1;

        if (dp.contains(n))
            return dp[n];

        int ans = climbStairs(n - 1) + climbStairs(n - 2);
        dp[n] = ans;
        return ans;
    }
};