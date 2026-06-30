#include <iostream>

using namespace std;

vector<int> prefixCalc(const vector<int> &nums)
{
    int n = nums.size();
    vector<int> prefix(n);

    if (n == 0)
        return prefix;

    prefix[0] = nums[0];

    for (int i = 1; i < n; i++)
    {
        prefix[i] = prefix[i - 1] + nums[i];
    }

    return prefix;
}

vector<int> suffixCalc(const vector<int> &nums)
{
    int n = nums.size();
    vector<int> suffix(n, 0);

    if (n == 0)
        return suffix;

    suffix[n - 1] = nums[n - 1];

    for (int i = n - 2; i >= 0; i--)
    {
        suffix[i] = nums[i] + suffix[i + 1];
    }

    return suffix;
}

int main()
{
    vector<int> nums = {1,1,1};

    vector<int> prefix = prefixCalc(nums);
    vector<int> suffix = suffixCalc(nums);

    int res = -1;

    for (int i = 0; i < nums.size(); i++)
    {
        if (suffix[i] == prefix[i])
        {
            res = i;
            break;
        }
    }

    cout << res << endl;
    return res;
}