#include <iostream>

using namespace std;

// https://leetcode.com/problems/invert-binary-tree/

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
    void invert(TreeNode *node)
    {
        if (node == nullptr)
        {
            return;
        }

        TreeNode *left = node->left;
        TreeNode *right = node->right;

        node->left = right;
        node->right = left;

        invert(node->left);
        invert(node->right);
        return;
    }

public:
    TreeNode *invertTree(TreeNode *root)
    {
        invert(root);
        return root;
    }
};

int main()
{
    Solution S;
}