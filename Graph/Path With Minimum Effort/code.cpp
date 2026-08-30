#include <iostream>

using namespace std;

// https://leetcode.com/problems/path-with-minimum-effort/description/

class Solution
{
    vector<int> dx = {1, -1, 0, 0};
    vector<int> dy = {0, 0, 1, -1};

    bool isValid(int row, int col, int rows, int cols)
    {
        return row >= 0 && row < rows && col >= 0 && col < cols;
    }

public:
    int minimumEffortPath(vector<vector<int>> &heights)
    {
        int rows = heights.size();
        int cols = heights[0].size();

        vector<vector<int>> effort(rows, vector<int>(cols, INT_MAX));

        // {effort, {row, col}}
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;

        effort[0][0] = 0;
        pq.push({0, {0, 0}});

        while (!pq.empty())
        {
            pair<int, pair<int, int>> current = pq.top();
            pq.pop();

            int currEffort = current.first;
            int row = current.second.first;
            int col = current.second.second;

            // Ignore outdated entry
            if (currEffort > effort[row][col])
            {
                continue;
            }

            for (int dir = 0; dir < 4; dir++)
            {
                int nextRow = row + dx[dir];
                int nextCol = col + dy[dir];

                if (!isValid(nextRow, nextCol, rows, cols))
                {
                    continue;
                }

                // Difference between current cell and neighbor
                // represents the edge weight.
                int weight = abs(heights[row][col] - heights[nextRow][nextCol]);

                // Path effort is the maximum edge weight
                // encountered along the path.
                int newEffort = max(currEffort, weight);

                // Found a path with lower effort
                if (newEffort < effort[nextRow][nextCol])
                {
                    effort[nextRow][nextCol] = newEffort;
                    pq.push({newEffort, {nextRow, nextCol}});
                }
            }
        }

        return effort[rows - 1][cols - 1];
    }
};