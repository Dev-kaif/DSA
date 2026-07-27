#include <iostream>

using namespace std;

// https://leetcode.com/problems/top-k-frequent-elements/$0

class Solution
{
    struct compare
    {
        // Returns true if 'a' should have LOWER priority than 'b'.

        // In other words:
        // true  -> b has higher priority than a
        // false -> a has higher (or equal) priority than b

        bool operator()(const pair<int, int> &a, const pair<int, int> &b)
        {

            // compare count
            if (a.first != b.first)
                return a.first > b.first;

            // compare num itself
            return a.second > b.second;
        }
    };

public:
    vector<int> topKFrequent(vector<int> &nums, int k)
    {
        // min heap for pair
        priority_queue<pair<int, int>, vector<pair<int, int>>, compare> pq;

        unordered_map<int, int> freq;
        vector<int> res;

        // Count frequencies
        for (int n : nums)
        {
            freq[n]++;
        }

        for (auto &[num, count] : freq)
        {
            pq.push({count, num});

            if (pq.size() > k)
            {
                pq.pop();
            }
        }

        while (!pq.empty())
        {
            int num = pq.top().second;
            res.push_back(num);
            pq.pop();
        }

        return res;
    }
};


int main()
{
    Solution S;
}
