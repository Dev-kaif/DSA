#include <iostream>
#include <stack>
#include <algorithm>

using namespace std;

// https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string/

int main()
{
    string s = "aaaabaaa";

    stack<char> st;
    string res;

    for (int i = 0; i < s.size(); i++)
    {
        // if empty push
        if (st.empty())
        {
            st.push(s[i]);
            continue;
        }

        // check if previous char and current char is same
        // (adjacent)
        if (st.top() == s[i])
        {
            st.pop();
            continue;
        }

        st.push(s[i]);
    }

    // empty the stack and create the string
    while (!st.empty())
    {
        res += st.top();
        st.pop();
    }

    // reverse to correct string order
    // (stack reverses the order)
    reverse(res.begin(), res.end());

    cout << res << endl;

    return 0;
}