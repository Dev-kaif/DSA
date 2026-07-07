#include <iostream>

using namespace std;

// https://leetcode.com/problems/maximum-number-of-balloons/description/

class Solution
{
    bool exist(unordered_map<char, int> &need,
               unordered_map<char, int> &have)
    {

        string find = "balloon";

        for (auto c : find)
        {
            if (have[c] < need[c])
            {
                return false;
            }
        }

        return true;
    }

public:
    int maxNumberOfBalloons(string text)
    {
        string find = "balloon";

        unordered_map<char, int> need, have;
        int res = INT_MAX;

        // frequency of characters needed to make one "balloon"
        for (int i = 0; i < find.size(); i++)
        {
            need[find[i]]++;
        }

        // frequency of characters available in text
        for (int i = 0; i < text.size(); i++)
        {
            have[text[i]]++;
        }

        // here in case : text has enough characters to make at least one "balloon"
        if (exist(need, have))
        {
            for (auto c : find)
            {
                int val = have[c] / need[c];
                res = min(res, val);
            }
        }

        return res == INT_MAX ? 0 : res;
    }
};

int main()
{
    Solution S;

    string text = "leetcode";

    int ans = S.maxNumberOfBalloons(text);

    cout << ans << endl;

    return 0;
}