#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int main()
{
    vector<int> nums = {-1, 2, 1, -4};

    int size = nums.size();
    int target = 1;
    int diff = INT_MAX;
    int result = 0;

    sort(nums.begin(), nums.end());

    for (int i = 0; i < size - 2; i++)
    {
        int left = i + 1;
        int right = size - 1;

        while (left < right)
        {
            int sum = nums[i] + nums[left] + nums[right];
            int d = abs(sum - target);

            if (diff > d)
            {
                diff = d;
                result = sum;
            }

            if (sum == target)
            {
                return sum;
            }

            else if (sum < target)
            {
                left++;
            }
            else
            {
                right--;
            }
        }
    }

    cout << result << endl;
    return result;
}