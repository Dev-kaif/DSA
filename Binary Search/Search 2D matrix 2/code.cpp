
#include <iostream>

using namespace std;

// https://leetcode.com/problems/search-a-2d-matrix-ii/

class Solution
{
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        int matrixRow = matrix.size() - 1;
        int matrixCol = matrix[0].size() - 1;

        int row = matrixRow;
        int col = 0;

        while (row >= 0 && col <= matrixCol)
        {
            int cornorVal = matrix[row][col];

            if (cornorVal == target)
            {
                return true;
            }

            if (cornorVal > target)
            {
                row--;
            }
            else
            {
                col++;
            }
        }

        return false;
    }
};

int main()
{
    Solution S;

    vector<vector<int>> nums = {{1, 4, 7, 11, 15}, {2, 5, 8, 12, 19}, {3, 6, 9, 16, 22}};
    int target = 5;

    int ans = S.searchMatrix(nums, target);

    cout << ans << endl;
}