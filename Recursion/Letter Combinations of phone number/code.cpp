#include <iostream>

using namespace std;

// https://leetcode.com/problems/letter-combinations-of-a-phone-number/

class Solution
{
    void combinations(string &digits, int index, int limit, string &temp, unordered_map<char, string> &map, vector<string> &ans)
    {

        if (index == limit)
        {
            ans.push_back(temp);
            return;
        }

        string choice = map[digits[index]];

        for (int j = 0; j < choice.size(); j++)
        {
            temp.push_back(choice[j]);
            combinations(digits, index + 1, limit, temp, map, ans);
            temp.pop_back();
        }
        return;
    }

public:
    vector<string> letterCombinations(string digits)
    {
        if (digits.empty())
            return {};

        unordered_map<char, string> map;

        map['2'] = "abc";
        map['3'] = "def";
        map['4'] = "ghi";
        map['5'] = "jkl";
        map['6'] = "mno";
        map['7'] = "pqrs";
        map['8'] = "tuv";
        map['9'] = "wxyz";

        int index = 0;
        int limit = digits.size();
        string temp;
        vector<string> ans;
        combinations(digits, index, limit, temp, map, ans);
        return ans;
    }
};

int main()
{
    Solution S;
}