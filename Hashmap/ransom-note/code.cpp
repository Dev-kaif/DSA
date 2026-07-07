#include <iostream>

using namespace std;

class Solution
{
public:
    bool canConstruct(string ransomNote, string magazine)
    {
        unordered_map<char, int> have, need;
        int res = 0;

        for (int i = 0; i < ransomNote.size(); i++)
        {
            have[ransomNote[i]]++;
        }

        for (int i = 0; i < magazine.size(); i++)
        {
            need[magazine[i]]++;
        }

        for (auto c : ransomNote)
        {
            if (have[c] > need[c])
            {
                return false;
            }
        }

        return true;
    }
};

int main()
{
    Solution S;

    string ransomNote = "aa", magazine = "baaa";

    int ans = S.canConstruct(ransomNote, magazine);

    cout << ans << endl;

    return 0;
}