#include <iostream>

using namespace std;

// https://leetcode.com/problems/number-of-islands

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

    void dfs(vector<vector<char>> &grid, vector<vector<bool>> &visited, int row, int col)
    {
        int rows = grid.size();
        int cols = grid[0].size();

        visited[row][col] = true;

        for (int direction = 0; direction < 4; direction++)
        {

            int nextRow = row + dx[direction];
            int nextCol = col + dy[direction];

            if (isValid(nextRow, nextCol, rows, cols) && grid[nextRow][nextCol] == '1' && !visited[nextRow][nextCol])
            {
                dfs(grid, visited, nextRow, nextCol);
            }
        }

        return;
    }

public:
    int numIslands(vector<vector<char>> &grid)
    {
        int rows = grid.size();
        int cols = grid[0].size();

        int islandCount = 0;

        vector<vector<bool>> visited(rows, vector<bool>(cols, false));

        for (int row = 0; row < rows; row++)
        {
            for (int col = 0; col < cols; col++)
            {

                if (grid[row][col] == '1' && !visited[row][col])
                {
                    dfs(grid, visited, row, col);
                    islandCount++;
                }
            }
        }

        return islandCount;
    }
};
