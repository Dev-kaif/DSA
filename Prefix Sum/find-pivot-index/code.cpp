#include <iostream>
#include <numeric>

using namespace std;

// https://leetcode.com/problems/find-pivot-index/description

int main()
{
    vector<int> nums = {1, 1, 1};

    int left = 0;
    int res = -1;

    int total = accumulate(nums.begin(), nums.end(), 0);

    for (int i = 1; i < nums.size(); i++)
    {
        // suffix of currect index
        int right = total - left - nums[i];

        if (left == right)
        {
            res = i;
            break;
        }

        // prefix for next index
        left += nums[i];
    }

    cout << res << endl;

    return res;
}