#include <iostream>

using namespace std;

// https://leetcode.com/problems/binary-search/

class Solution
{
public:
    int search(vector<int> &nums, int target)
    {
        int size = nums.size();

        int low = 0;
        int high = size - 1;

        while (low <= high)
        {
            // int mid = (low + high) / 2;

            // Overflow-safe way to calculate the middle index.
            // (low + high) can overflow if both are very large.
            int mid = low + (high - low) / 2;

            if (nums[mid] == target)
            {
                return mid;
            }
            else if (nums[mid] > target)
            {
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }

        return -1;
    }
};

int main()
{
    Solution S;

    vector<int> nums = {-1, 0, 3, 5, 9, 12};
    int target = 9;

    int ans = S.search(nums, target);

    cout << ans << endl;
}