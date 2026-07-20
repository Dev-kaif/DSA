
#include <iostream>

using namespace std;

// https://leetcode.com/problems/search-a-2d-matrix/

class Solution
{
    int findCandidateRow(vector<vector<int>> &matrix, int target)
    {
        int rowCount = matrix.size();
        int res = -1;

        for (int row = 0; row < rowCount; row++)
        {
            int firstElement = matrix[row][0];

            if (target >= firstElement)
            {
                res = row;
            }
            else
            {
                break;
            }
        }

        return res;
    }

public:
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        int columnCount = matrix[0].size();
        int lastColumn = columnCount - 1;

        // last element of matrix
        if (matrix.back().back() < target)
        {
            return false;
        }

        int candidateRow = findCandidateRow(matrix, target);

        if (candidateRow == -1)
        {
            return false;
        }

        int left = 0;
        int right = lastColumn;

        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            int currentElement = matrix[candidateRow][mid];

            if (currentElement == target)
            {
                return true;
            }
            else if (currentElement > target)
            {
                right = mid - 1;
            }
            else
            {
                left = mid + 1;
            }
        }

        return false;
    }
};

int main()
{
    Solution S;

    vector<vector<int>> nums = {{1, 3, 5, 7}, {10, 11, 16, 20}, {23, 30, 34, 60}};
    int target = 55;

    int ans = S.searchMatrix(nums, target);

    cout << ans << endl;
}