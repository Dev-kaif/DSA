#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> main()
{
    vector<int> nums = {-1, 0, 1, 2, -1, -4};
    int size = nums.size();

    vector<vector<int>> result;

    sort(nums.begin(), nums.end());

    for (int i = 0; i < size - 2; i++)
    {
        if (i > 0 && nums[i] == nums[i - 1])
            continue;

        int target = -nums[i];

        int left = i + 1;
        int right = size - 1;

        while (left < right)
        {
            int sum = nums[left] + nums[right];

            if (sum == target)
            {
                result.push_back({nums[i], nums[left], nums[right]});

                // cout << nums[i] << " " << nums[left] << " " << nums[right] << endl;
                left++;
                right--;

                while (left < right && nums[left] == nums[left - 1])
                    left++;

                while (left < right && nums[right] == nums[right + 1])
                    right--;
            }

            if (sum < target)
            {
                left++;
            }

            if (sum > target)
            {
                right--;
            }
        }
    }

    return result;
}