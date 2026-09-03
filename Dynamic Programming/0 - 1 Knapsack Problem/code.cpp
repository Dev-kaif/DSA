#include <iostream>

using namespace std;

// https://www.geeksforgeeks.org/problems/0-1-knapsack-problem0945/1

class Solution
{
    vector<vector<int>> dp;

public:
    int solve(vector<int> &val, vector<int> &wt, int cap, int curr)
    {
        int n = val.size();

        if (curr == n)
        {
            return 0;
        }

        if (dp[curr][cap] != -1)
        {
            return dp[curr][cap];
        }

        if (wt[curr] > cap)
        {
            int ans = solve(val, wt, cap, curr + 1);
            dp[curr][cap] = ans;
            return ans;
        }

        int take = val[curr] + solve(val, wt, cap - wt[curr], curr + 1);
        int skip = solve(val, wt, cap, curr + 1);

        int ans = max(skip, take);
        dp[curr][cap] = ans;

        return ans;
    }

    int knapsack(int capacity, vector<int> &val, vector<int> &wt)
    {
        int n = val.size();
        dp = vector<vector<int>>(n, vector<int>(capacity + 1, -1));
        return solve(val, wt, capacity, 0);
    }
};
