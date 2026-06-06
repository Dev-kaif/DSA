#include <iostream>

using namespace std;

// https://www.geeksforgeeks.org/problems/longest-k-unique-characters-substring0853/1

int main()
{
    string s = "aaba cbebebe";
    int k = 3;

    int low = 0;
    int n = s.size();
    int res = INT_MIN;

    unordered_map<char, int> f;

    for (int high = 0; high < n; high++)
    {
        f[s[high]]++;

        while (f.size() > k)
        {
            f[s[low]]--;

            if (f[s[low]] == 0)
            {
                f.erase(s[low]);
            }

            low++;
        }

        if (f.size() == k)
        {
            int len = high - low + 1;
            res = max(res, len);
        }
    }

    cout << res << endl;
    return res == INT_MIN ? -1 : res;
}