#include <iostream>

using namespace std;

// https://www.geeksforgeeks.org/problems/0-1-knapsack-problem0945/1

class Solution
{
public:
    int knapsack(int capacity, vector<int> &val, vector<int> &wt)
    {

        int n = val.size();

        vector<vector<int>> dp(n + 1, vector<int>(capacity + 1));

        // put default value as 0 in last row
        // in last row no item left so 0
        for (int cap = 0; cap <= capacity; cap++)
        {
            dp[n][cap] = 0;
        }

        for (int item = n - 1; item >= 0; item--)
        {

            for (int cap = 0; cap <= capacity; cap++)
            {

                // Current item is too heavy, so skip it.
                if (cap < wt[item])
                {
                    dp[item][cap] = dp[item + 1][cap];
                    continue;
                }

                // Take current item.
                int take = val[item] + dp[item + 1][cap - wt[item]];

                // Skip current item.
                int skip = dp[item + 1][cap];

                dp[item][cap] = max(take, skip);
            }
        }

        return dp[0][capacity];
    }
};
