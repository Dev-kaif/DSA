#include <iostream>

using namespace std;

// https://leetcode.com/problems/daily-temperatures/

vector<int> main()
{
    vector<int> temperatures = {73, 74, 75, 71, 69, 72, 76, 73};

    int n = temperatures.size();
    int end = n - 1;

    vector<int> res(n);
    stack<int> st;

    res[end] = 0;
    st.push(end);

    for (int i = end - 1; i >= 0; i--)
    {
        int crr = temperatures[i];

        while (!st.empty() && temperatures[st.top()] <= crr)
        {
            st.pop();
        }

        if (st.empty())
        {
            res[i] = 0;
        }
        else
        {
            res[i] = st.top() - i;
        }

        st.push(i);
    }

    return res;
}