#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> nums = {2, 0, 2, 1, 1, 0};

    vector<int> zero;
    vector<int> one;
    vector<int> two;

    for (int i = 0; i < nums.size(); i++)
    {
        int value = nums[i];

        if (value == 0)
            zero.push_back(value);
        else if (value == 1)
            one.push_back(value);
        else
            two.push_back(value);
    }

    nums.clear(); // remove old data

    nums.insert(nums.end(), zero.begin(), zero.end());
    nums.insert(nums.end(), one.begin(), one.end());
    nums.insert(nums.end(), two.begin(), two.end());

    for (int i = 0; i < nums.size(); i++)
    {
        cout << nums[i] << " ";
    }
    cout << endl;
}