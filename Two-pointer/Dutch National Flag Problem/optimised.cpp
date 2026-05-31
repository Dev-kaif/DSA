#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> nums = {2, 0, 2, 1, 1, 0};
    
    int zero = 0, one = 0, two = 0;

    for (int i = 0; i < nums.size(); i++)
    {
        int value = nums[i];

        if (value == 0)
            zero++;
        else if (value == 1)
            one++;
        else
            two++;
    }

    nums.clear(); // remove old data
    nums.insert(nums.end(), zero, 0);
    nums.insert(nums.end(), one, 1);
    nums.insert(nums.end(), two, 2);

    for (int i = 0; i < nums.size(); i++)
    {
        cout << nums[i] << " ";
    }
    cout << endl;
}