#include <iostream>

using namespace std;

// https://leetcode.com/problems/max-consecutive-ones-iii/description/

int main()
{
    vector<int> nums = {0,0,1,1,0,0,1,1,1,0,1,1,0,0,0,1,1,1,1};
    int k = 3;

    vector<int> f(2, 0);

    int n = nums.size();
    
    int low = 0, high = 0, res = 0;

    for (high = 0; high < n; high++)
    {
        f[nums[high]]++;
        int len = high - low + 1;

        int maxcount = f[1];
        
        // count of zero
        int diff = len - maxcount;

        // if number of zero are more than replacable(k) 
        while (diff > k)
        {
            f[nums[low]]--;
            low++;

            len = high - low + 1;
            maxcount = f[1];

            // recount no. of zero
            diff = len - maxcount;
        }

        len = high - low + 1;
        res = max(res, len);
    }

    cout << res << endl;

    return res;
}