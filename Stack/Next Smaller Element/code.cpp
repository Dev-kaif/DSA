#include <iostream>

using namespace std;

// https://www.geeksforgeeks.org/problems/immediate-smaller-element1142/1

vector<int> main()
{
    vector<int> arr = {4, 8, 5, 2, 25};

    int n = arr.size();
    int size = n - 1;

    stack<int> st;
    vector<int> res(n);

    st.push(arr[size]);
    res[size] = -1;

    for (int i = size - 1; i >= 0; i--)
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