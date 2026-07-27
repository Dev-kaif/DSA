#include <iostream>

using namespace std;

// https://leetcode.com/problems/kth-largest-element-in-an-array/

// We create heap of K size

// so that we can pop the top -> pop the min values -> so at last only kth largest element remain 

// Keep only the k largest elements in a min heap.
// If heap size exceeds k, remove the smallest.
// The top of the heap is the k-th largest element.

class Solution
{
public:
    int findKthLargest(vector<int> &nums, int k)
    {
        priority_queue<int, vector<int>, greater<int>> pq;
        
        for (auto n : nums)
        {
            pq.push(n);
            if (pq.size() > k)
            {
                pq.pop();
            }
        }

        return pq.top();
    }
};

int main()
{
    Solution S;

    vector<int> nums = {7, 10, 4, 3, 20, 15};
    int k = 3;

    int ans = S.findKthLargest(nums, k);

    cout << ans << endl;
    return 0;
}

