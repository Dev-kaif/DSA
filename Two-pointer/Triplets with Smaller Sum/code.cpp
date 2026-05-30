#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    vector<int> arr = {-2, 0, 1, 3};
    int sum = 2;

    int size = arr.size();
    int result = 0;

    sort(arr.begin(), arr.end());

    for (int i = 0; i < size - 2; i++)
    {
        int left = i + 1;
        int right = size - 1;

        while (left < right)
        {
            int total = arr[i] + arr[left] + arr[right];

            if (total >= sum)
            {
                right--;
            }
            else
            {
                result = result + (right - left);
                left++;
            }
        }
    }

    cout << result << endl;
    return result;
}