#include <iostream>
#include <cmath>

using namespace std;

// https://leetcode.com/problems/ipo/

class Solution
{
public:
    int findMaximizedCapital(int k, int w, vector<int> &profits, vector<int> &capital)
    {

        // Min heap storing {capital, profit}.
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minCapital;

        // Max heap storing profits.
        priority_queue<int> maxProfit;

        // Add all projects to the capital heap.
        for (int i = 0; i < profits.size(); i++)
        {
            minCapital.push({capital[i], profits[i]});
        }

        while (k--)
        {
            // Move all affordable projects to the profit heap.
            while (!minCapital.empty() && minCapital.top().first <= w)
            {
                maxProfit.push(minCapital.top().second);
                minCapital.pop();
            }

            // No affordable projects left.
            if (maxProfit.empty())
                break;

            // Select the most profitable affordable project.
            w += maxProfit.top();
            maxProfit.pop();
        }

        return w;
    }
};

int main()
{
    Solution S;
}