#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    vector<int> nums = {0, 1, 0, 3, 12};
    int low = 0;
    int high = 1;

    while (high < nums.size())
    {
        if (nums[high] != 0)
        {
            swap(nums[low], nums[high]);
            low++;
        }
        high++;
    }

    for (int i = 0; i < nums.size(); i++)
    {
        cout << nums[i] << " ";
    }
    cout << endl;
}