#include <iostream>

using namespace std;

// https://leetcode.com/problems/path-sum/description/

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
    void check(TreeNode *node, int targetSum, int sum, bool &res)
    {
        if (!node || res)
        {
            return;
        }

        sum += node->val;

        if (leaf(node))
        {
            if (sum == targetSum)
            {
                res = true;
            }
            return;
        }

        check(node->left, targetSum, sum, res);
        check(node->right, targetSum, sum, res);
        return;
    }

public:
    bool hasPathSum(TreeNode *root, int targetSum)
    {
        if (!root)
        {
            return false;
        }
        bool res = false;
        int sum = 0;
        check(root, targetSum, sum, res);
        return res;
    }
};

int main()
{
    Solution S;
}