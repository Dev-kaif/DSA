#include <iostream>
#include <vector>

using namespace std;
// https://leetcode.com/problems/two-sum/description/

// O(n²)
int main()
{
    vector<int> arr = {3,2,5,7,8,4};

    int sum = 0;
    int target = 6;

    for (int i = 0; i < arr.size(); i++)
    {
        for (int j = i + 1; j < arr.size(); j++)
        {
            if (arr[i] + arr[j] == target)
            {
                cout << "[" << i << ", " << j << "]" << endl;
            }
        }
    }
}