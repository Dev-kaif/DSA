#include <iostream>

using namespace std;

// https://leetcode.com/problems/insert-interval/

vector<vector<int>> merge(vector<vector<int>> &intervals)
{
    vector<vector<int>> res;

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

vector<vector<int>> main()
{
    vector<vector<int>> intervals = {{1, 3}, {2, 6}, {8, 10}, {15, 18}};
    vector<int> newInterval = {4, 8};

    // handles case where interval is empty
    if (intervals.empty())
    {
        return {newInterval};
    }

    sort(intervals.begin(), intervals.end());

    bool inserted = false;
    vector<vector<int>> res;

    for (int i = 0; i < intervals.size(); i++)
    {
        vector<int> start = intervals[i];

        if (inserted == false && start >= newInterval)
        {
            res.emplace_back(newInterval);
            inserted = true;
        }

        res.emplace_back(intervals[i]);
    }

    // if loop breaks means insertion need to be done at end
    if (!inserted)
    {
        res.emplace_back(newInterval);
    }

    res = merge(res);

    return res;
}
