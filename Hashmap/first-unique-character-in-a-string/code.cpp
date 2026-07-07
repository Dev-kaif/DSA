#include <iostream>

using namespace std;

class Solution
{
public:
    int firstUniqChar(string s)
    {
        unordered_map<char, int> f;
        int n = s.size();

        for (int i = 0; i < n; i++)
        {
            f[s[i]]++;
        }

        for (int i = 0; i < n; i++)
        {
            int freq = f[s[i]];

            if (freq == 1)
            {
                return i;
            }
        }

        return -1;
    }
};

int main()
{
    Solution S;

    string s = "leetcode";

    int ans = S.firstUniqChar(s);

    cout << ans << endl;
    return 0;
}