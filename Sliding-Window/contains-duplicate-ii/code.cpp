#include <iostream>
#include <unordered_set>

using namespace std;

// https://leetcode.com/problems/contains-duplicate-ii/description/
int main()
{
    vector<int> nums = {99, 99};
    int k = 2;

    unordered_set<int> window;

    for (int high = 0; high < nums.size(); high++)
    {
        // find(x) searches for x in the set.
        // If x exists, find(x) returns an iterator pointing to x.

        // If x does NOT exist, find(x) returns window.end().
        // window.end() is a special iterator representing
        // "one past the last element" (not an actual element).
        
        // Therefore:
        // find(x) != window.end()  -> x exists
        // find(x) == window.end()  -> x does not exist

        if (window.find(nums[high]) != window.end())
        {
            return true;
        }

        window.insert(nums[high]);

        if (window.size() > k)
        {
            window.erase(nums[high - k]);
        }
    }

    return false;
}