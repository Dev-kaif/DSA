#include <iostream>

using namespace std;

// https://leetcode.com/problems/koko-eating-bananas/

class Solution
{

    long long eatingHour(vector<int> &piles, int speed)
    {
        long long totalHour = 0;

        for (int pile : piles)
        {
            totalHour += pile / speed;
            if (pile % speed != 0)
            {
                totalHour += 1;
            }
        }

        return totalHour;
    }

public:
    int minEatingSpeed(vector<int> &piles, int h)
    {
        int low = 1;

        int high = 0;
        for (auto pile : piles)
        {
            high = max(high, pile);
        }

        int res = high;

        while (low <= high)
        {
            int mid = low + (high - low) / 2;

            if (eatingHour(piles, mid) > h)
            {
                low = mid + 1;
            }
            else
            {
                res = mid;
                high = mid - 1;
            }
        }

        return res;
    }
};

int main()
{
    Solution S;

    vector<int> nums = {3, 6, 7, 11};
    int h = 8;

    int ans = S.minEatingSpeed(nums, h);

    cout << ans << endl;
}