#include <iostream>

using namespace std;

// https://leetcode.com/problems/peak-index-in-a-mountain-array/
// https://leetcode.com/problems/find-peak-element/

class Solution
{
public:
    int peakIndexInMountainArray(vector<int> &arr)
    {
        int low = 0;
        int high = arr.size() - 1;

        while (low < high)
        {
            int mid = low + (high - low) / 2;

            if (arr[mid] > arr[mid + 1])
            {
                // it can be on left side
                // Or mid itself could be the pick
                high = mid;
            }
            else
            {

                // if next element is greater than mid than peak element cant be
                // mid

                // and it will be in right side so update the low
                low = mid + 1;
            }
        }

        return high;
    }
};

int main()
{
    Solution S;

    vector<int> nums = {24, 69, 100, 99, 79, 78, 67, 36, 26, 19};

    int ans = S.peakIndexInMountainArray(nums);

    cout << ans << endl;
}