#include <iostream>

using namespace std;

// https://leetcode.com/problems/merge-intervals/

vector<vector<int>> main()
{
    vector<vector<int>> intervals = {{1, 3}, {2, 6}, {8, 10}, {15, 18}};

    vector<vector<int>> res;

    sort(intervals.begin(), intervals.end());

    int start1 = intervals[0][0];
    int end1 = intervals[0][1];

    for (int i = 0; i < intervals.size(); i++)
    {
        int start2 = intervals[i][0];
        int end2 = intervals[i][1];

        if (end1 >= start2)
        {
            // start1 = start1;
            end1 = max(end1, end2);
            continue;
        }

        res.push_back({start1, end1});

        start1 = start2;
        end1 = end2;
    }

    res.push_back({start1, end1});

    return res;
}
