#include <iostream>

using namespace std;

// https://leetcode.com/problems/subarray-sums-divisible-by-k/

int main()
{
    vector<int> nums = {4, 5, 0, -2, -3, 1};
    int k = 5;

    unordered_map<int, int> f;
    int sum = 0;
    int res = 0;

    // prefix of index 0 in array
    f[0] = 1;

    for (int i = 0; i < nums.size(); i++)
    {

        sum += nums[i];

        // for handling negative
        int remainder = ((sum % k) + k) % k;

        int freq = f[remainder];

        res += freq;

        f[remainder]++;
    }

    cout << res << endl;

    return res;
}