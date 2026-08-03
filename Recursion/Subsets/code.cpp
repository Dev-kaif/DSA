#include <iostream>

using namespace std;

// https://leetcode.com/problems/subsets/description/

class Solution
{
    void printSubArrays(vector<int> &arr, int index, vector<int> &temp, vector<vector<int>> &ans)
    {
        int n = arr.size();

        if (index == n)
        {
            ans.push_back(temp);
            return;
        }

        // Don't take arr[index]
        printSubArrays(arr, index + 1, temp, ans);

        // Take arr[index]
        temp.push_back(arr[index]);
        printSubArrays(arr, index + 1, temp, ans);
        temp.pop_back();
    }

public:
    vector<vector<int>> subsets(vector<int> &nums)
    {
        vector<vector<int>> ans;
        vector<int> temp;

        printSubArrays(nums, 0, temp, ans);

        return ans;
    }
};

int main()
{
    Solution S;

    vector<int> arr = {1, 2, 3};

    S.subsets(arr);

    return 0;
}