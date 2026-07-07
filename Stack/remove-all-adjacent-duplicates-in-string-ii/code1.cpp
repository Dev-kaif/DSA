#include <iostream>

using namespace std;

// https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string-ii/description/

int main()
{
    string s = "abcd";
    int k = 2;

    string res = "";

    // first = character 
    // second = current consecutive count of that character
    stack<pair<char, int>> st;

    for (int i = 0; i < s.size(); i++)
    {
        char c = s[i];

        // stack is empty OR current character != st.top().first
        if (st.empty() || st.top().first != c)
        {
            st.push({c, 1});
            continue;
        }

        // here in case : charcter = st.top().first
        if (st.top().second < k - 1)
        {
            pair<char, int> top = st.top();
            st.pop();

            st.push({c, top.second + 1});

            continue;
        }

        // here st.top().second = k - 1
        st.pop();
    }

    while (!st.empty())
    {
        pair<char, int> top = st.top();

        for (int i = 0; i < top.second; i++)
        {
            res += top.first;
        }

        st.pop();
    }

    reverse(res.begin(), res.end());

    cout << res << endl;
    
    return 0;
}