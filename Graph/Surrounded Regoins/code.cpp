#include <iostream>

using namespace std;

// https://leetcode.com/problems/surrounded-regions/description/

class Solution
{
    bool isValid(int row, int col, int rows, int cols)
    {
        return row < rows && row >= 0 && col >= 0 && col < cols;
    }

    vector<int> dx = {-1, 1, 0, 0};
    vector<int> dy = {0, 0, -1, 1};

    void dfs(vector<vector<char>> &board, int row, int col)
    {
        int rows = board.size();
        int cols = board[0].size();

        // Mark the current 'O' as safe.
        board[row][col] = '#';

        // Explore all four neighboring cells
        for (int dir = 0; dir < 4; dir++)
        {
            int nextRow = row + dx[dir];
            int nextCol = col + dy[dir];

            // Continue DFS only for valid, unvisited 'O' cells
            if (isValid(nextRow, nextCol, rows, cols) &&
                board[nextRow][nextCol] == 'O')
            {
                // every 'O' connected to it is also safe and cannot be surrounded.
                dfs(board, nextRow, nextCol);
            }
        }
    }

public:
    void solve(vector<vector<char>> &board)
    {
        int rows = board.size();
        int cols = board[0].size();

        int row, col;

        // Find all 'O's on the first column.
        // Any 'O' connected to the boundary is safe.
        for (row = 0; row < rows; row++)
        {
            if (board[row][0] == 'O')
            {
                dfs(board, row, 0);
            }
        }

        // Find all 'O's on the first row.
        for (col = 0; col < cols; col++)
        {
            if (board[0][col] == 'O')
            {
                dfs(board, 0, col);
            }
        }

        // Find all 'O's on the last column.
        for (row = 0; row < rows; row++)
        {
            if (board[row][cols - 1] == 'O')
            {
                dfs(board, row, cols - 1);
            }
        }

        // Find all 'O's on the last row.
        for (col = 0; col < cols; col++)
        {
            if (board[rows - 1][col] == 'O')
            {
                dfs(board, rows - 1, col);
            }
        }

        // At this point:
        // 'O'  -> surrounded region, so convert it to 'X'
        // '#'  -> safe region connected to the boundary, restore it to 'O'
        for (row = 0; row < rows; row++)
        {
            for (col = 0; col < cols; col++)
            {
                if (board[row][col] == 'O')
                {
                    board[row][col] = 'X';
                }
                else if (board[row][col] == '#')
                {
                    board[row][col] = 'O';
                }
            }
        }

        return;
    }
};