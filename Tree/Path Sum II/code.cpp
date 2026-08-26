#include <iostream>

using namespace std;

// https://leetcode.com/problems/path-sum-ii/

struct TreeNode
{
    int val;         // Value stored in the node
    TreeNode *left;  // Pointer to the left child
    TreeNode *right; // Pointer to the right child

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode *left, TreeNode *right)
        : val(x), left(left), right(right) {}
};

class Solution
{
    bool leaf(TreeNode *node)
    {
        if (node->left || node->right)
        {
            return false;
        }
        return true;
    }
    void pathArray(TreeNode *node, int targetSum, int sum, vector<int> &temp,
                   vector<vector<int>> &ans)
    {

        if (!node)
        {
            return;
        }

        sum += node->val;
        temp.push_back(node->val);

        if (leaf(node))
        {
            if (sum == targetSum)
            {
                ans.push_back(temp);
            }
            temp.pop_back();
            return;
        }

        pathArray(node->left, targetSum, sum, temp, ans);
        pathArray(node->right, targetSum, sum, temp, ans);
        temp.pop_back();
        return;
    }

public:
    vector<vector<int>> pathSum(TreeNode *root, int targetSum)
    {
        vector<vector<int>> ans;
        vector<int> temp;
        int sum = 0;
        pathArray(root, targetSum, sum, temp, ans);
        return ans;
    }
};

int main()
{
    Solution S;
}