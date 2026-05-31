#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    vector<int> nums = {2, 0, 2, 1, 1, 0};

    int low = 0, mid = 0, high = nums.size() - 1;

    while (mid <= high)
    {
        int value = nums[mid];

        if (value == 0)
        {
            swap(nums[mid], nums[low]);
            low++;
            mid++;
        }
        else if (value == 1)
        {
            mid++;
        }
        else
        {
            swap(nums[mid], nums[high]);
            high--;
        }
    }

    for (int i = 0; i < nums.size(); i++)
    {
        cout << nums[i] << " ";
    }
    cout << endl;
}