#include <iostream>

using namespace std;

int digitSquareSum(int n)
{
    int sum = 0;
    while (n > 0)
    {
        int d = n % 10;
        n = n / 10;
        sum += d * d;
    }
    return sum;
}

int main()
{
    int n = 19;

    int slow = 0;
    int fast = 0;

    while (fast != 1)
    {
        slow = digitSquareSum(n);

        fast = digitSquareSum(n);
        fast = digitSquareSum(n);

        if (slow == fast & slow != 1)
        {
            return false;
        }
    }

    return true;
}