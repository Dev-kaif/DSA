
#include <iostream>

using namespace std;

// https://www.geeksforgeeks.org/problems/allocate-minimum-number-of-pages0937/1

class Solution
{
    bool canAssignLimit(vector<int> &books, int limit, int stud)
    {

        int pages = 0;
        int k = 1;

        for (int i = 0; i < books.size(); i++)
        {
            
            if (pages + books[i] <= limit)
            {
                pages += books[i];
            }
            else
            {
                k++;
                pages = books[i];

                if (k > stud)
                {
                    return false;
                }
            }
        }

        return true;
    }

public:
    int findPages(vector<int> &arr, int k)
    {
        int size = arr.size();

        int res = 0;

        if (size < k)
        {
            return -1;
        }

        int low = 0;

        int high = 0;
        for (auto a : arr)
        {
            low = max(low, a);
            high += a;
        }

        while (low <= high)
        {
            int guess = low + (high - low) / 2;

            int isPossible = canAssignLimit(arr, guess, k);

            if (isPossible)
            {
                res = guess;
                high = guess - 1;
            }
            else
            {
                low = guess + 1;
            }
        }

        return res;
    }
};

int main()
{
    Solution S;

    vector<int> nums = {12, 34, 67, 90};
    int k = 2;

    int ans = S.findPages(nums, k);

    cout << ans << endl;
}