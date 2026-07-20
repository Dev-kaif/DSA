
#include <iostream>

using namespace std;

// https://leetcode.com/problems/kth-smallest-element-in-a-sorted-matrix/description/

class Solution
{
    int smallRankInMatrix(vector<vector<int>> &matrix, int target)
    {
        int matrixRow = matrix.size() - 1;
        int matrixCol = matrix[0].size() - 1;

        int row = matrixRow;
        int col = 0;

        int rank = 0;

        while (row >= 0 && col <= matrixCol)
        {
            int cornorVal = matrix[row][col];

            if (cornorVal > target)
            {
                row--;
            }
            else
            {
                rank += row + 1;
                col++;
            }
        }

        return rank;
    }

public:
    int kthSmallest(vector<vector<int>> &matrix, int k)
    {
        // last row
        int matrixRow = matrix.size() - 1;
        // last column
        int matrixCol = matrix[0].size() - 1;

        int low = matrix[0][0];
        int high = matrix[matrixRow][matrixCol];

        int res = 0;

        while (low <= high)
        {
            int guess = low + (high - low) / 2;

            // calculate the rank
            int targetRank = smallRankInMatrix(matrix, guess);

            // match the ranks
            if (targetRank >= k)
            {
                res = guess;
                high = guess - 1;
            }
            else
            {
                low = guess + 1;
            }
        }

        return res;
    }
};

int main()
{
    Solution S;

    vector<vector<int>> matrix = {{1, 4, 7, 11, 15}, {2, 5, 8, 12, 19}, {3, 6, 9, 16, 22}};
    int target = 5;

    int ans = S.kthSmallest(matrix, target);

    cout << ans << endl;
}