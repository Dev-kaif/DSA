#include <iostream>
#include <stack>
#include <algorithm>

using namespace std;

bool main()
{
    string s = "()[]{}";

    stack<char> st;

    for (int i = 0; i < s.size(); i++)
    {
        char ch = s[i];

        if (ch == '(' || ch == '[' || ch == '{')
        {
            st.push(ch);
            continue;
        }

        if (st.empty())
        {
            return false;
        }

        char top = st.top();
        st.pop();

        if (ch == ')' && top != '(')
        {
            return false;
        }

        if (ch == ']' && top != '[')
        {
            return false;
        }

        if (ch == '}' && top != '{')
        {
            return false;
        }
    }

    if (!st.empty())
    {
        return false;
    }

    return true;
}