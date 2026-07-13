#include <iostream>

using namespace std;

// https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/description/

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
            int mid = low + (high - low) / 2;
            int guess = nums[mid];

            // Target found.
            if (guess == target)
            {
                return mid;
            }

            // Check where does Mid lie.

            // Example:
            // [0,1,2 | 4,5,6,7]
            //  Part 1    Part 2

            // After Rotation:
            // [4,5,6,7 | 0,1,2]
            //  Part 2    Part 1

            // Any value greater than the last element belongs to Part 2.
            if (guess > nums[size - 1])
            {
                // mid lies in Part 2 (left sorted half).

                // Target is greater than guess.
                if (target > guess)
                {
                    // Both are in Part 2.
                    // Since Part 2 is sorted, search right.
                    low = mid + 1;
                }
                else
                {
                    // Target lesser than First element,
                    // so it belongs to Part 1.
                    if (target < nums[0])
                    {
                        // Target cannot lie to the left of a Part 2 element.
                        // Move into Part 1.
                        low = mid + 1;
                    }
                    else
                    {
                        // Target is also in Part 2 and is smaller than guess.
                        // Search left.
                        high = mid - 1;
                    }
                }
            }
            else
            {
                // Mid lies in Part 1 (right sorted half).

                // Target is smaller than guess.
                if (target < guess)
                {
                    // Both are in Part 1.
                    // Search left.
                    high = mid - 1;
                }
                else
                {
                    // Target is greater than guess.
                    if (target <= nums[size - 1])
                    {
                        // Target also belongs to Part 1.
                        // Search right.
                        low = mid + 1;
                    }
                    else
                    {
                        // Target belongs to Part 2.
                        // It cannot lie to the right of a Part 1 element.
                        // Move into Part 2.
                        high = mid - 1;
                    }
                }
            }
        }

        return -1;
    }
};

int main()
{
    Solution S;

    vector<int> nums = {4, 5, 6, 7, 0, 1, 2};
    int target = 0;

    int ans = S.search(nums, target);

    cout << ans << endl;
    return 0;
}