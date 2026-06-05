#include <iostream>

using namespace std;

// https://leetcode.com/problems/subarray-product-less-than-k/description/

int main()
{
    vector<int> nums = {10, 5, 2, 6};
    int target = 100;

    int n = nums.size();

    int low = 0;
    int high = 0;

    long long product = 1;
    int res = 0;

    while (high < n)
    {
        product *= nums[high];

        while (product>=target)
        {
            product /= nums[low];
            low++;
        }

        res += high - low + 1;

        high++;
    }

    return res;

    cout << res << endl;
}