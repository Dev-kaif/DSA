#include <iostream>

using namespace std;

class Solution
{
public:
    int maxNumberOfBalloons(string text)
    {
        unordered_map<char, int> mp;
        for (int i = 0; i < text.length(); i++)
        {
            mp[text[i]]++;
        }
        return min({mp['b'], mp['a'], mp['l'] / 2, mp['o'] / 2, mp['n']});
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