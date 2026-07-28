#include <iostream>
#include <cmath>

using namespace std;

// https://leetcode.com/problems/k-closest-points-to-origin/description/

class Solution
{
    struct compare
    {
        bool operator()(const pair<int, int> &a, const pair<int, int> &b)
        {

            // compare distance
            if (a.first != b.first)
            {
                return a.first < b.first;
            }

            // compare index
            return a.second < b.second;
        }
    };

public:
    vector<vector<int>> kClosest(vector<vector<int>> &points, int k)
    {
        // max heap
        priority_queue<pair<int, int>, vector<pair<int, int>>, compare> pq;

        vector<vector<int>> res;

        for (int index = 0; index < points.size(); index++)
        {
            const vector<int> &point = points[index];

            int x = point[0];
            int y = point[1];

            int dist = (x * x + y * y);

            pq.push({dist, index});

            if (pq.size() > k)
            {
                pq.pop();
            }
        }

        while (!pq.empty())
        {
            int index = pq.top().second;
            res.push_back(points[index]);
            pq.pop();
        }

        return res;
    }
};

int main()
{
    Solution S;
}