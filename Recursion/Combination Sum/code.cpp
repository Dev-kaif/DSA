#include <iostream>

using namespace std;

class Solution {
    void combination(vector<int>& candidates, int target, int index, vector<int>& temp, int &sum, vector<vector<int>> &res) {
        if (index == candidates.size()) {
            if (sum == target)
                res.push_back(temp);
            return;
        }

        // choice of not taking
        combination(candidates, target, index + 1, temp, sum, res);

        // choice of taking
        if (sum + candidates[index] <= target) {
            temp.push_back(candidates[index]);
            sum += candidates[index];
            combination(candidates, target, index, temp, sum, res);
            temp.pop_back();
            sum -= candidates[index];
        }
        return;
    }

public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> temp;
        vector<vector<int>> res;
        int sum = 0;
        combination(candidates, target, 0, temp, sum, res);
        return res;
    }
};

int main()
{
    Solution S;
}