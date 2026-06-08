#include <iostream>
using namespace std;

// https://leetcode.com/problems/arithmetic-slices/description

int main()
{
    vector<int> nums = {1, 2, 3, 4};

    int n = nums.size();

    // if count is less than three , there is nothing to compare
    if (n < 3)
        return 0;

    int low = 0;
    int high = 1;

    // calc first diff
    int diff = nums[low] - nums[high];

    // calculates if previous found subarray and current subarray can be mixed to create new bigger subarray
    int curr = 0;

    int res = 0;

    while (high < n - 1)
    {
        low++;
        high++;

        int newDiff = nums[low] - nums[high];

        // if diff is same then upp the result
        if (diff == newDiff)
        {
            // Same difference means the arithmetic sequence continues.
            // Previous arithmetic slices can be extended by the new element,
            // and we also get one new length-3 arithmetic slice.
            curr++;
            res += curr;
        }
        // if diff isnt same means , you cant add the not same diff subarray in window to next subarray
        else
        {
            // The arithmetic sequence is broken.
            // Any arithmetic slices that ended at the previous index
            // can no longer be extended, so reset the count.
            curr = 0;
        }

        diff = newDiff;
    }

    return res;
}
