#include <iostream>

using namespace std;

// https://leetcode.com/problems/top-k-frequent-words/

class Solution
{
    struct compare
    {
        bool operator()(const pair<int, string> &a,
                        const pair<int, string> &b)
        {

            // smaller frequency = higher priority
            if (a.first != b.first)
                return a.first > b.first;

            // lexicographically larger has lower priority
            return a.second < b.second;
        }
    };

public:
    vector<string> topKFrequent(vector<string> &words, int k)
    {

        // min heap for pair
        priority_queue<pair<int, string>, vector<pair<int, string>>, compare> pq;

        unordered_map<string, int> freq;
        vector<string> res;

        // Count frequencies
        for (auto str : words)
        {
            freq[str]++;
        }

        for (auto &[str, count] : freq)
        {
            pq.push({count, str});

            if (pq.size() > k)
            {
                pq.pop();
            }
        }

        while (!pq.empty())
        {
            string s = pq.top().second;
            res.push_back(s);
            pq.pop();
        }

        reverse(res.begin(), res.end());
        return res;
    }
};

int main()
{
    Solution S;
}
