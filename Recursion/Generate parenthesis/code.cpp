#include <iostream>

using namespace std;

class Solution
{
    void generate(int openCount, int closeCount, int limit, string &temp,
                  vector<string> &ans)
    {

        if (openCount == limit && closeCount == limit)
        {
            ans.push_back(temp);
        }

        if (openCount < limit)
        {
            temp.push_back('(');
            generate(openCount + 1, closeCount, limit, temp, ans);
            temp.pop_back();
        }

        if (closeCount < openCount)
        {
            temp.push_back(')');
            generate(openCount, closeCount + 1, limit, temp, ans);
            temp.pop_back();
        }

        return;
    }

public:
    vector<string> generateParenthesis(int n)
    {
        vector<string> ans;
        string temp;
        generate(0, 0, n, temp, ans);
        return ans;
    }
};
