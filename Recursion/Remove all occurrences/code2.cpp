#include <iostream>

using namespace std;

// https://www.geeksforgeeks.org/problems/remove-all-occurrences-of-a-character-in-a-string/1

class Solution
{
    string func(string &s, char c, int low)
    {

        if (low == s.size())
        {
            return "";
        }

        string ans = func(s, c, low + 1);

        if (s[low] == c)
            return ans;

        return s[low] + ans;
    }

public:
    // Function to remove all occurrences of the character from the string
    void removeCharacter(string &s, char c)
    {
        s = func(s, c, 0);
    }
};

int main()
{
    Solution S;

    return 0;
}