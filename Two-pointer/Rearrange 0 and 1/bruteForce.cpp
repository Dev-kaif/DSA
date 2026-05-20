
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    vector<int> arr = {0, 1, 0, 1, 0, 0, 1, 1, 1, 0};

    int n = arr.size();

    vector<int> v1;
    vector<int> v2;

    for (int i = 0; i < n; i++)
    {
        if (arr[i] == 0)
        {
            v1.push_back(arr[i]);
        }
        else
        {
            v2.push_back(arr[i]);
        }
    }

    v1.insert(v1.end(), v2.begin(), v2.end());

    arr = v1;
}