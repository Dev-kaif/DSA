#include <iostream>
#include <cmath>

using namespace std;

// https://leetcode.com/problems/ipo/

class Solution
{
public:
    int findMaximizedCapital(int k, int w, vector<int> &profits,
                             vector<int> &capital)
    {

        int n = profits.size();
        vector<pair<int, int>> projects(n);

        priority_queue<int> maxCapital;

        for (int i = 0; i < n; i++)
        {
            projects[i] = {capital[i], profits[i]};
        }

        sort(projects.begin(), projects.end());

        int i = 0;
        while (k--)
        {

            while (i < n && projects[i].first <= w)
            {
                maxCapital.push(projects[i].second);
                i++;
            }

            if (maxCapital.empty())
            {
                break;
            }

            w += maxCapital.top();
            maxCapital.pop();
        }

        return w;
    }
};

int main()
{
    Solution S;
}