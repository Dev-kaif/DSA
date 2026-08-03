#include <iostream>

using namespace std;

// https://www.geeksforgeeks.org/problems/remove-all-occurrences-of-a-character-in-a-string/1

class Solution
{
    void func(string &s, string &temp, char c, int low)
    {

        if (low == s.size())
            return;

        if (s[low] != c)
            temp.push_back(s[low]);

        func(s, temp, c, low + 1);
    }

public:
    // Function to remove all occurrences of the character from the string
    void removeCharacter(string &s, char c)
    {
        string temp;
        func(s, temp, c, 0);
        s = temp;
        return;
    }
};

int main()
{
    Solution S;

    return 0;
}