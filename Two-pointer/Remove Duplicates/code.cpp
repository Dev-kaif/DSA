#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> arr = {1, 1, 2, 2, 3, 3, 6, 7, 7};

    int low = 1, high = 1;

    while (high < arr.size())
    {
        
        if (arr[high] == arr[high - 1])
        {
            high++;
        }
        else
        {
            arr[low] = arr[high];
            low++;
            high++;
        }
    }

    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    cout << "unique: " << low << endl;
}