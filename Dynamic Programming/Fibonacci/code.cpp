#include <iostream>

using namespace std;

// https://leetcode.com/problems/fibonacci-number/description/

class Solution
{
    unordered_map<int, int> dp;

public:
    int fib(int n)
    {

        if (n <= 1)
        {
            return n;
        }

        if (dp.find(n) != dp.end())
        {
            return dp[n];
        }

        int prev = fib(n - 1);
        int prevPrev = fib(n - 2);

        int ans = prev + prevPrev;
        dp[n] = ans;

        return ans;
    }
};