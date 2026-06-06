#include <iostream>

using namespace std;

// https://leetcode.com/problems/longest-substring-without-repeating-characters/description/

int main()
{
    string s = "abcabcbb";

    int low = 0;

    int n = s.size();
    int res = 0;

    unordered_map<char, int> f;

    for (int high = 0; high < n; high++)
    {
        f[s[high]]++;

        int len = high - low + 1;

        while (f.size() < len)
        {
            f[s[low]]--;

            if (f[s[low]] == 0)
            {
                f.erase(s[low]);
            }

            low++;

            len = high - low + 1;
        }

        res = max(res, len);
    }

    cout << res << endl;
    return res;
}