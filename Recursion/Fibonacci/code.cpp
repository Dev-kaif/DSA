#include <iostream>

using namespace std;

// https://leetcode.com/problems/fibonacci-number/submissions/2089764836/

class Solution
{
public:
    int fib(int n)
    {

        if (n <= 1)
        {
            return n;
        }

        int prev = fib(n - 1);
        int prevPrev = fib(n - 2);

        return prev + prevPrev;
    }
};

int main()
{
    Solution S;

    int n = 5;

    int ans = S.fib(n);

    cout << ans << endl;

    return 0;
}