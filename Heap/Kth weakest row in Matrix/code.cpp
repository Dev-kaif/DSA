#include <iostream>
#include <cmath>

using namespace std;

// https://leetcode.com/problems/the-k-weakest-rows-in-a-matrix/

class Solution
{
    struct compare
    {
        bool operator()(const pair<int, int> &a, const pair<int, int> &b)
        {
            // compare strength
            if (a.first != b.first)
            {
                return a.first < b.first;
            }

            // compare row number
            return a.second < b.second;
        }
    };

    int measureStrength(const vector<int> &row)
    {
        int sum = 0;

        for (int i : row)
        {
            sum += i;
        }

        return sum;
    }

public:
    vector<int> kWeakestRows(vector<vector<int>> &mat, int k)
    {
        // max heap
        priority_queue<pair<int, int>, vector<pair<int, int>>, compare> pq;
        vector<int> res;

        for (int i = 0; i < mat.size(); i++)
        {
            const vector<int> &row = mat[i];
            int strength = measureStrength(row);
            pq.push({strength, i});

            if (pq.size() > k)
            {
                pq.pop();
            }
        }

        while (!pq.empty())
        {
            int row = pq.top().second;
            res.push_back(row);
            pq.pop();
        }

        reverse(res.begin(), res.end());

        return res;
    }
};

int main()
{
    Solution S;
}