#include <iostream>

using namespace std;

// https://leetcode.com/problems/next-greater-element-ii/description/

vector<int> main()
{
    vector<int> nums = {1, 2, 1};

    int n = nums.size();
    int end = n - 1;

    vector<int> res(n);

    stack<int> st;

    for (int i = end - 1; i >= 0; i--)
    {
        st.push(nums[i]);
    }

    for (int i = end; i >= 0; i--)
    {
        while (!st.empty() && st.top() <= nums[i])
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
        st.push(nums[i]);
    }

    return res;
}