#include <iostream>

using namespace std;

// https://leetcode.com/problems/contiguous-array/description/

int main()
{
    vector<int> nums = {0, 1, 1, 1, 1, 1, 0, 0, 0};

    unordered_map<int, int> f;
    int n = nums.size();
    vector<int> count(2, 0);

    int res = 0;

    for (int i = 0; i < n; i++)
    {
        count[nums[i]]++;

        int diff = count[0] - count[1];

        if (diff == 0)
        {
            res = max(res, i + 1);
            continue;
        }

        if (f.count(diff))
        {
            int prevIndex = f[diff];
            int len = i - prevIndex;
            res = max(res, len);
            continue;
        }

        f[diff] = i;
    }

    cout << res << endl;

    return res;
}