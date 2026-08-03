#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution
{
    bool isPalindrome(string &s, int low, int high)
    {
        while (low < high)
        {
            if (s[low] != s[high])
                return false;

            low++;
            high--;
        }

        return true;
    }

    void combination(string &s, int startIndex, vector<string> &temp, vector<vector<string>> &res)
    {
        int n = s.size();

        if (startIndex == n)
        {
            res.push_back(temp);
            return;
        }

        for (int end = startIndex; end < n; end++)
        {

            if (isPalindrome(s, startIndex, end))
            {

                int len = end - startIndex + 1;
                string choice = s.substr(startIndex, len);

                temp.push_back(choice);
                // end + 1 as start
                // bcz we have already exploared string till end
                combination(s, end + 1, temp, res);
                temp.pop_back();
            }
        }
    }

public:
    vector<vector<string>> partition(string s)
    {
        vector<string> temp;
        vector<vector<string>> res;

        combination(s, 0, temp, res);

        return res;
    }
};

int main()
{
    Solution S;

    string s = "aab";

    vector<vector<string>> ans = S.partition(s);

    for (auto &partition : ans)
    {
        cout << "{ ";
        for (auto &str : partition)
        {
            cout << "\"" << str << "\" ";
        }
        cout << "}\n";
    }

    return 0;
}