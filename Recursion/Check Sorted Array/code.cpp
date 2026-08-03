#include <iostream>

using namespace std;

// https://www.geeksforgeeks.org/problems/check-if-an-array-is-sorted0701/1

class Solution
{
    bool sorted(vector<int> &arr, int low, int high)
    {
        if (low >= high)
        {
            return true;
        }

        if (arr[low] > arr[low + 1])
        {
            return false;
        }

        return sorted(arr, low + 1, high);
    }

public:
    bool isSorted(vector<int> &arr)
    {
        return sorted(arr, 0, arr.size() - 1);
    }
};

int main()
{
    Solution S;

    return 0;
}