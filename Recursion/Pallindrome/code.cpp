#include <iostream>

using namespace std;

// https://www.geeksforgeeks.org/problems/palindrome-string0817/1

class Solution
{
    bool func(string &s, int low, int high)
    {

        if (low >= high)
            return true;

        if (s[low] != s[high])
            return false;

        return func(s, low + 1, high - 1);
    }

public:
    bool isPalindrome(string &s)
    {

        int low = 0;
        int high = s.size() - 1;

        return func(s, low, high);
    }
};

int main()
{
    Solution S;
    return 0;
}