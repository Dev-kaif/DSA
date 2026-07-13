#include <iostream>

using namespace std;

// https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/description/

class Solution
{
public:
    int findMin(vector<int> &nums)
    {
        int low = 0;
        int high = nums.size() - 1;

        // Stores the smallest value seen so far.
        int ans = INT_MAX;

        while (low <= high)
        {
            int mid = low + (high - low) / 2;

            // If the current search range is already sorted,
            // then nums[low] is the minimum of this range.
            if (nums[low] <= nums[high])
            {
                ans = min(ans, nums[low]);
                break;
            }

            // Save the current middle element because
            // it could be the minimum.
            ans = min(ans, nums[mid]);

            // Decide which half to discard.

            // nums[mid] > nums[high] means mid lies in the
            // left (larger) portion of the rotated array.
            
            // Therefore, the minimum must be on the right.
            if (nums[mid] > nums[high])
            {
                low = mid + 1;
            }
            else
            {
                // Mid lies in the right (smaller) portion.
                // The minimum could be to the left of mid.
                high = mid - 1;
            }
        }

        return ans;
    }
};

int main()
{
    Solution S;

    vector<int> nums = {4, 5, 6, 7, 0, 1, 2};

    int ans = S.findMin(nums);

    cout << ans << endl;
    return 0;
}