#include <iostream>

using namespace std;

// https://leetcode.com/problems/minimum-window-substring/description/

bool compare(vector<int> &have, vector<int> &need)
{
    for (int i = 0; i < 256; i++)
    {
        if (have[i] < need[i])
        {
            return false;
        }
    }
    return true;
}

int main()
{
    string s = "ADOBECODEBANC";
    string t = "ABC";


    vector<int> have(256, 0);
    vector<int> need(256, 0);

    int low = 0;
    int high = 0;

    int start = 0;
    int end = INT_MIN;

    for (int i = 0; i < t.size(); i++)
    {
        need[t[i]]++;
    }

    for (high = 0; high < s.size(); high++)
    {
        have[s[high]]++;

        while (compare(have, need))
        {
            start = low;

            int len = high - low + 1;
            end = max(end, len);

            have[s[low]]--;
            low++;
        }
    }

    string result = end == INT_MIN ? "" : s.substr(start, end);

    cout << result << endl;

    return 0;
}