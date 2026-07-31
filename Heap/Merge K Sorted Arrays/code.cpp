#include <iostream>
#include <cmath>

using namespace std;

// https://www.geeksforgeeks.org/problems/merge-k-sorted-arrays/1

class Solution
{
public:
    vector<int> mergeArrays(vector<vector<int>> &mat)
    {
        vector<int> res;
        // 	rows
        int n = mat.size();
        // 	colume
        int m = mat[0].size();

        // value , row , colume
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;

        for (int i = 0; i < n; i++)
        {
            pq.push({mat[i][0], {i, 0}});
        }

        while (!pq.empty())
        {
            auto top = pq.top();
            int row = top.second.first;
            int col = top.second.second;
            pq.pop();

            res.push_back(top.first);

            if (col == m - 1)
                continue;

            pq.push({mat[row][col + 1], {row, col + 1}});
        }

        return res;
    }
};

int main()
{
    Solution S;
}