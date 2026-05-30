#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> nums = {-1, 0, 1, 2, -1, -4};
    int size = nums.size();
    int i = 0, j = i + 1, k = j + 1;

    for (int i = 0; i < size; i++)
    {
        for (int j = i + 1; j < size; j++)
        {
            for (int k = j + 1; k < size; k++)
            {
                if (nums[i] + nums[j] + nums[k] == 0)
                {
                    cout << i << " " << j << " " << k << endl;
                }
            }
        }
    }
}