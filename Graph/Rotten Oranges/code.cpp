#include <iostream>

using namespace std;

// https://leetcode.com/problems/rotting-oranges/description/

class Solution
{
    vector<int> dx = {-1, 1, 0, 0};
    vector<int> dy = {0, 0, -1, 1};

    bool isValid(int row, int col, int rows, int cols)
    {
        if (row < 0 || row >= rows || col < 0 || col >= cols)
        {
            return false;
        }
        return true;
    }

    void currupt(vector<vector<int>> &grid, int row, int col, queue<pair<int, int>> &q, int &fresh)
    {

        int rows = grid.size();
        int cols = grid[0].size();

        for (int dir = 0; dir < 4; dir++)
        {
            int nextRow = row + dx[dir];
            int nextCol = col + dy[dir];

            if (isValid(nextRow, nextCol, rows, cols) &&
                grid[nextRow][nextCol] == 1)
            {
                // mark as rotten
                grid[nextRow][nextCol] = -2;
                fresh--;
                q.push({nextRow, nextCol});
            }
        }

        return;
    }

public:
    int orangesRotting(vector<vector<int>> &grid)
    {
        int rows = grid.size();
        int cols = grid[0].size();

        int time = 0;
        int fresh = 0;
        queue<pair<int, int>> q;

        // creating freq map of fresh and adding rotten to queue
        for (int row = 0; row < rows; row++)
        {
            for (int col = 0; col < cols; col++)
            {
                int val = grid[row][col];

                if (val == 1)
                {
                    fresh++;
                }
                else if (val == 2)
                {
                    q.push({row, col});
                }
            }
        }

        // BFS
        while (!q.empty() && fresh > 0)
        {
            time++;
            int size = q.size();

            while (size--)
            {
                auto [row, col] = q.front();
                q.pop();
                currupt(grid, row, col, q, fresh);
            }
        }

        return fresh > 0 ? -1 : time;
    }
};