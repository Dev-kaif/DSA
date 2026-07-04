#include <iostream>

using namespace std;

// https://leetcode.com/problems/interval-list-intersections/

vector<vector<int>> main()
{

    vector<vector<int>> firstList = {{0, 2}, {5, 10}, {13, 23}, {24, 25}};
    vector<vector<int>> secondList = {{1, 5}, {8, 12}, {15, 24}, {25, 26}};

    int first = 0;
    int second = 0;

    vector<vector<int>> res;

    while (first < firstList.size() && second < secondList.size())
    {

        vector<int> &firstItem = firstList[first];
        vector<int> &secondItem = secondList[second];

        int start = max(firstItem[0], secondItem[0]);
        int end = min(firstItem[1], secondItem[1]);

        if (start <= end)
        {
            res.push_back({start, end});
        }

        if (firstItem[1] < secondItem[1])
        {
            first++;
        }
        else
        {
            second++;
        }
    }

    return res;
}