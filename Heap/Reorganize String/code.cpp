#include <iostream>
#include <cmath>

using namespace std;

// https://leetcode.com/problems/reorganize-string/

class Solution
{
    struct Compare
    {
        bool operator()(const pair<int, char> &a, const pair<int, char> &b)
        {
            // Compare frequencies.
            if (a.first != b.first)
            {
                return a.first < b.first;
            }

            // If frequencies are equal, prioritize the lexicographically larger character.
            return a.second < b.second;
        }
    };

public:
    string reorganizeString(string s)
    {
        // Max heap
        priority_queue<pair<int, char>, vector<pair<int, char>>, Compare> pq;

        unordered_map<char, int> freq;
        string res;

        // Last character placed in the result.
        char lastPlaced;

        // Count the frequency
        for (char ch : s)
            freq[ch]++;

        // Push all {frequency, character} pairs into the heap.
        for (const auto &[ch, count] : freq)
        {
            pq.push({count, ch});
        }

        while (!pq.empty())
        {
            // Take the character with the highest remaining frequency.
            auto [count, ch] = pq.top();
            pq.pop();

            // If this character is the same as the last placed character,

            // try to use the next most frequent character instead.
            if (!res.empty() && lastPlaced == ch)
            {

                // No alternative character is available.
                if (pq.empty())
                    return "";

                auto [count2, ch2] = pq.top();
                pq.pop();

                // Place the second most frequent character.
                res.push_back(ch2);
                lastPlaced = ch2;

                // Decrease its remaining frequency and
                // push it back if it still has occurrences left.
                if (--count2 > 0)
                    pq.push({count2, ch2});

                // Push the first character back since it wasn't used.
                pq.push({count, ch});
            }
            else
            {

                // Safe to place the current character.
                res.push_back(ch);
                lastPlaced = ch;

                // Decrease its remaining frequency and
                // push it back if it still has occurrences left.
                if (--count > 0)
                    pq.push({count, ch});
            }
        }

        // If not all characters were placed,
        // reorganization was impossible.
        if (res.size() != s.size())
            return "";

        return res;
    }
};

int main()
{
    Solution S;
}