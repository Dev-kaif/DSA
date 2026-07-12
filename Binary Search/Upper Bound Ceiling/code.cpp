#include <iostream>

using namespace std;

// https://www.geeksforgeeks.org/problems/ceil-in-a-sorted-array/1

class Solution
{
public:
    int findCeil(vector<int> &arr, int x)
    {

        int low = 0;
        int high = arr.size() - 1;
        int res = -1;

        while (low <= high)
        {

            int mid = low + (high - low) / 2;

            if (arr[mid] >= x)
            {
                res = mid;
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }

        return res;
    }
};

int main()
{
    Solution S;

    vector<int> nums = {-1, 0, 3, 5, 9, 12};

    int target = 9;
    

    int ans = S.findCeil(nums, target);

    cout << ans << endl;
}