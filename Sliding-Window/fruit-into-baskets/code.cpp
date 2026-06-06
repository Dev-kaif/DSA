#include <iostream>

using namespace std;

// https://leetcode.com/problems/fruit-into-baskets/description/

int main()
{
    vector<int> fruits = {};
    int k = 2;

    int low = 0;
    int n = fruits.size();
    int res = 0;

    unordered_map<int, int> f;

    for (int high = 0; high < n; high++)
    {
        f[fruits[high]]++;

        while (f.size() > k)
        {
            f[fruits[low]]--;

            if (f[fruits[low]] == 0)
            {
                f.erase(fruits[low]);
            }

            low++;
        }

        int len = high - low + 1;
        res = max(res, len);
    }

    cout << res << endl;

    return res == INT_MIN ? -1 : res;
}