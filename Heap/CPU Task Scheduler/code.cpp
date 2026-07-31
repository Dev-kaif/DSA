#include <iostream>
#include <cmath>

using namespace std;

// https://leetcode.com/problems/task-scheduler/

class Solution
{
public:
    int leastInterval(vector<char> &tasks, int n)
    {
        priority_queue<pair<int, char>> child;

        unordered_map<char, int> map;
        unordered_map<char, int> free;

        int seat = 1;

        for (char &ch : tasks)
        {
            map[ch]++;
            free[ch] = 1;
        }

        for (auto &[ch, freq] : map)
        {
            child.push({freq, ch});
        }

        while (!child.empty())
        {
            priority_queue<pair<int, char>> corner;

            while (!child.empty())
            {
                auto top = child.top();
                child.pop();

                int freq = top.first;
                char ch = top.second;

                if (free[ch] <= seat)
                {
                    if (freq > 1)
                        child.push({freq - 1, ch});

                    free[ch] = seat + n + 1;
                    break;
                }
                else
                {
                    corner.push(top);
                }
            }

            while (!corner.empty())
            {
                child.push(corner.top());
                corner.pop();
            }

            seat++;
        }

        // bcz in last we will leave an empty seat
        return seat - 1;
    }
};

int main()
{
    Solution S;
}