#include <iostream>

using namespace std;

// https://leetcode.com/problems/binary-tree-preorder-traversal/

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
    void preOrder(TreeNode *node, vector<int> &ans)
    {
        if (node == nullptr)
        {
            return;
        }
        // node data push
        ans.push_back(node->val);

        // call left
        preOrder(node->left, ans);

        // call right
        preOrder(node->right, ans);
        return;
    }

public:
    vector<int> preorderTraversal(TreeNode *root)
    {
        vector<int> ans;
        preOrder(root, ans);
        return ans;
    }
};

int main()
{
    Solution S;
}