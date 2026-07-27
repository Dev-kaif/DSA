#include <iostream>

using namespace std;

// https://www.geeksforgeeks.org/problems/kth-smallest-element5635/1

// MIN-HEAP
/*
class Solution
{
public:
    int kthSmallest(vector<int> &arr, int k)
    {
        int target = k - 1;

        // min heap
        priority_queue<int, vector<int>, greater<int>> pq;

        for (auto a : arr)
        {
            pq.push(a);
        }

        while (target--)
        {
            pq.pop();
        }

        return pq.top();
    }
};
*/

// MAX-HEAP
class Solution
{
public:
    int kthSmallest(vector<int> &arr, int k)
    {
        priority_queue<int> pq;

        for (int x : arr)
        {
            pq.push(x);

            if (pq.size() > k)
                pq.pop();
        }

        return pq.top();
    }
};

int main()
{
    Solution S;

    vector<int> nums = {7, 10, 4, 3, 20, 15};
    int k = 3;

    int ans = S.kthSmallest(nums, k);

    cout << ans << endl;
    return 0;
}