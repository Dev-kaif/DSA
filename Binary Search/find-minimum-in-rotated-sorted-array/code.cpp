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

        while (low < high)
        {
            int mid = low + (high - low) / 2;

            // already sorted
            if (nums[low] <= nums[high])
            {
                return nums[low];
            }

            // mid is part of part-2
            if (nums[mid] > nums[high])
            {
                low = mid + 1;
            }
            else
            {
                // mid is part of part-1

                // keep mid in search radius
                // bcz mid can be actual ans
                high = mid;
            }
        }

        // high = low at the end
        return nums[high];
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