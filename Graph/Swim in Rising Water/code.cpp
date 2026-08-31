#include <iostream>

using namespace std;

// https://leetcode.com/problems/swim-in-rising-water/description/

class Solution
{
    vector<int> dx = {-1, 1, 0, 0};
    vector<int> dy = {0, 0, -1, 1};

    bool isValid(int row, int col, int rows, int cols)
    {
        return row >= 0 && row < rows && col >= 0 && col < cols;
    }

public:
    int swimInWater(vector<vector<int>> &grid)
    {
        int rows = grid.size();
        int cols = grid[0].size();

        // time[row][col] = minimum water level required to reach this cell.
        vector<vector<int>> time(rows, vector<int>(cols, INT_MAX));

        // {water level, {row, col}}
        // The cell requiring the lowest water level is processed first.
        priority_queue<pair<int, pair<int, int>>,
                       vector<pair<int, pair<int, int>>>,
                       greater<pair<int, pair<int, int>>>>
            pq;

        // We start at the height of the starting cell.
        time[0][0] = grid[0][0];
        pq.push({grid[0][0], {0, 0}});

        while (!pq.empty())
        {
            pair<int, pair<int, int>> current = pq.top();
            pq.pop();

            int currTime = current.first;
            int row = current.second.first;
            int col = current.second.second;

            // Ignore an outdated entry.
            if (currTime > time[row][col])
            {
                continue;
            }

            // Explore all four directions.
            for (int dir = 0; dir < 4; dir++)
            {
                int nextRow = row + dx[dir];
                int nextCol = col + dy[dir];

                if (!isValid(nextRow, nextCol, rows, cols))
                {
                    continue;
                }

                // To reach the next cell, water must be at least
                // its height. We also need to account for the
                // highest cell encountered so far.
                int requiredTime = max(currTime, grid[nextRow][nextCol]);

                // Found a path requiring less time/water level.
                if (requiredTime < time[nextRow][nextCol])
                {
                    time[nextRow][nextCol] = requiredTime;
                    pq.push({requiredTime, {nextRow, nextCol}});
                }
            }
        }

        return time[rows - 1][cols - 1];
    }
};