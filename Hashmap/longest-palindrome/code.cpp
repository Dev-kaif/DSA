#include <iostream>

using namespace std;

// https://leetcode.com/problems/longest-palindrome/

// There are two types of palindrome
// - even OR odd palindrome
// even : abba
// odd : abcba

// palindrome can have pairs on both sides and 
// at most one odd character in middle

class Solution
{
public:
    int longestPalindrome(string s)
    {
        unordered_map<char, int> freq;
        int res = 0;
        bool odd = false;

        for (auto c : s)
        {
            freq[c]++;
        }

        for (auto f : freq)
        {
            // if even value add whole freq
            if (f.second % 2 == 0)
            {
                res += f.second;
                continue;
            }

            odd = true;

            // if odd value , then make it even by - 1
            int oddVal = f.second;
            res += oddVal - 1;
        }

        // if odd value was present in freq , add one odd value in middle
        return odd ? res + 1 : res;
    }
};

int main()
{
    Solution S;

    string s = "aaabbb";

    // ab a ba
    // ab b ba

    // hence ans = 5

    int ans = S.longestPalindrome(s);

    cout << ans << endl;
    return 0;
}