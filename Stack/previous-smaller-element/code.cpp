#include <iostream>

using namespace std;

// www.geeksforgeeks.org/problems/previous-smaller-element/1

vector<int> main()
{
    vector<int> arr = {10, 4, 2, 20, 40, 12, 30};

    int n = arr.size();

    stack<int> st;
    vector<int> res(n);

    st.push(arr[0]);
    res[0] = -1;

    for (int i = 1; i < n; i++)
    {
        int crrVal = arr[i];

        while (!st.empty() && st.top() >= crrVal)
        {
            st.pop();
        }

        if (st.empty())
        {
            res[i] = -1;
        }
        else
        {
            res[i] = st.top();
        }

        st.push(crrVal);
    }

    return res;
}