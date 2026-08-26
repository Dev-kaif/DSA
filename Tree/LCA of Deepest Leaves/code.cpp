#include <iostream>

using namespace std;

// https://leetcode.com/problems/lowest-common-ancestor-of-deepest-leaves/

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
    int calcMaxDepth(TreeNode *root)
    {

        if (root == nullptr)
        {
            return 0;
        }

        int left = calcMaxDepth(root->left);
        int right = calcMaxDepth(root->right);

        return 1 + max(left, right);
    }

    TreeNode *dfs(TreeNode *node, int maxDepth, int currentDepth)
    {

        if (node == nullptr)
            return nullptr;

        if (maxDepth - 1 == currentDepth)
            return node;

        TreeNode *left = dfs(node->left, maxDepth, currentDepth + 1);
        TreeNode *right = dfs(node->right, maxDepth, currentDepth + 1);

        if (left && right)
            return node;

        return left ? left : right;
    }

public:
    TreeNode *lcaDeepestLeaves(TreeNode *root)
    {

        int maxDepth = calcMaxDepth(root);
        int currentDepth = 0;

        return dfs(root, maxDepth, currentDepth);
    }
};

int main()
{
    Solution S;
}