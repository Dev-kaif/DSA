#include <iostream>

using namespace std;

// https://leetcode.com/problems/find-the-duplicate-number/

int main()
{
    vector<int> nums = {1, 3, 4, 2, 2};

    int slow = 0;
    int fast = 0;

    while (true)
    {
        slow = nums[slow];
        fast = nums[fast];
        fast = nums[fast];

        if (slow == fast)
        {
            slow = 0;
            while (slow != fast)
            {
                slow = nums[slow];
                fast = nums[fast];
            }
            cout << slow << endl;
            return slow;
        }
    }
    return -1;
}