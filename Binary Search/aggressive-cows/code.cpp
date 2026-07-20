
#include <iostream>

using namespace std;

// https://www.geeksforgeeks.org/problems/aggressive-cows/1

class Solution
{
    bool canCowPlace(vector<int> &arr, int totalCow, int guess)
    {
        int cow = 1;
        int lastplaced = arr[0];

        for (int i = 1; i < arr.size(); i++)
        {
            int dist = arr[i] - lastplaced;

            if (dist >= guess)
            {
                cow++;
                lastplaced = arr[i];
            }
            if (cow == totalCow)
                return true;
        }

        return false;
    }

public:
    int aggressiveCows(vector<int> &arr, int k)
    {
        sort(arr.begin(), arr.end());
        int size = arr.size();
        int cow = k;

        int low = 1;
        int high = arr[size - 1] - arr[0];
        int res = 0;

        while (low <= high)
        {
            int guess = low + (high - low) / 2;

            bool possibleDist = canCowPlace(arr, cow, guess);

            if (possibleDist)
            {
                low = guess + 1;
                res = guess;
            }
            else
            {
                high = guess - 1;
            }
        }

        return res;
    }
};

int main()
{
    Solution S;

    vector<int> nums = {1, 2, 4, 8, 9};
    int k = 3;

    int ans = S.aggressiveCows(nums, k);

    cout << ans << endl;
}