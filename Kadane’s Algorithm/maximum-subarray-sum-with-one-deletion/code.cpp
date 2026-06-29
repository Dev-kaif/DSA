#include <iostream>

using namespace std;

// https://leetcode.com/problems/maximum-subarray-sum-with-one-deletion/description/

int main()
{
    vector<int> arr = {1, -2, 0, 3};

    int res = arr[0];

    int noDelete = arr[0];
    int oneDelete = 0;

    for (int i = 1; i < arr.size(); i++)
    {
        oneDelete = max(oneDelete + arr[i], noDelete);
        noDelete = max(arr[i], noDelete + arr[i]);

        res = max({res, noDelete, oneDelete});
    }
    
    cout << res << endl;

    return res;
}