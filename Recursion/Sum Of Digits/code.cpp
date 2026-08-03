class Solution
{
    int sum(int n)
    {

        if (n == 0)
            return 0;

        int lastDigit = n % 10;
        n = n / 10;

        int remainingSum = sum(n);

        return remainingSum + lastDigit;
    }

public:
    int sumOfDigits(int n)
    {
        return sum(n);
    }
};
