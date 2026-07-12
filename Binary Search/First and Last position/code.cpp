#include <iostream>

using namespace std;

class Solution
{

    int firstOccurrence(vector<int> &nums, int target)
    {
        int start = 0;
        int end = nums.size() - 1;
        int ans = -1;

        while (start <= end)
        {
            int mid = start + (end - start) / 2;

            if (nums[mid] == target)
            {
                ans = mid;

                // Search on the left
                // cut off the right size
                end = mid - 1;
            }
            else if (nums[mid] < target)
            {
                start = mid + 1;
            }
            else
            {
                end = mid - 1;
            }
        }
        return ans;
    }

    int lastOccurrence(vector<int> &nums, int target)
    {
        int start = 0;
        int end = nums.size() - 1;
        int ans = -1;

        while (start <= end)
        {
            int mid = start + (end - start) / 2;

            if (nums[mid] == target)
            {
                ans = mid;
                // cut off the left size
                start = mid + 1; // Search on the right
            }
            else if (nums[mid] < target)
            {
                start = mid + 1;
            }
            else
            {
                end = mid - 1;
            }
        }
        return ans;
    }

public:
    vector<int> searchRange(vector<int> &nums, int target)
    {

        int first = firstOccurrence(nums, target);
        int last = lastOccurrence(nums, target);

        return {first, last};
    }
};

int main()
{
    Solution S;

    vector<int> nums = {-1, 0, 3, 5, 5, 9, 12};

    int target = 5;

    vector<int> ans = S.searchRange(nums, target);

    // cout << ans << endl;
    return 0;
}