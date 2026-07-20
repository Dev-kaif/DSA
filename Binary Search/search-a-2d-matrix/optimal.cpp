
#include <iostream>

using namespace std;

// https://leetcode.com/problems/search-a-2d-matrix/

class Solution
{
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        int columnCount = matrix[0].size();
        int rowCount = matrix.size();

        // last element of matrix
        if (matrix.back().back() < target)
        {
            return false;
        }

        int left = 0;
        int right = (rowCount * columnCount) - 1;

        while (left <= right)
        {
            int mid = left + (right - left) / 2;

            int row = mid / columnCount;
            int coloum = mid % columnCount;

            int currentElement = matrix[row][coloum];

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