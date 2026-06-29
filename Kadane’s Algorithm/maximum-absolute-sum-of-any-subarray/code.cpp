#include <iostream>

using namespace std;

int main()
{
    vector<int> nums = {1, -3, 2, 3, -4};

    int res = nums[0];
    int maxVal = nums[0];
    int minVal = nums[0];

    int maxBestEnd = nums[0];
    int minBestEnd = nums[0];

    for (int i = 1; i < nums.size(); i++)
    {
        maxBestEnd = max(maxBestEnd + nums[i], nums[i]);
        maxVal = max(maxVal, maxBestEnd);

        minBestEnd = min(minBestEnd + nums[i], nums[i]);
        minVal = min(minVal, minBestEnd);

        res = max(abs(maxVal), abs(minVal));
    }

    cout << res << endl;

    return abs(res);
}