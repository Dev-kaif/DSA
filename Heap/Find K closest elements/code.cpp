#include <iostream>
#include <cmath>

using namespace std;

// https://leetcode.com/problems/find-k-closest-elements/description/

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

            // compare point
            return a.second < b.second;
        }
    };

public:
    vector<int> findClosestElements(vector<int> &arr, int k, int x)
    {
        // max heap
        priority_queue<pair<int, int>, vector<pair<int, int>>, compare> pq;

        vector<int> res;

        for (int point : arr)
        {
            int dist = abs(point - x);
            pq.push({dist, point});

            if (pq.size() > k)
            {
                pq.pop();
            }
        }

        while (!pq.empty())
        {
            int point = pq.top().second;
            res.push_back(point);
            pq.pop();
        }

        sort(res.begin(), res.end());

        return res;
    }
};

int main()
{
    Solution S;
}