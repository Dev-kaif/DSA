#include <iostream>

using namespace std;

// https://leetcode.com/problems/binary-tree-inorder-traversal/

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
    void inOrder(TreeNode *node, vector<int> &ans)
    {
        if (node == nullptr)
        {
            return;
        }

        // call left
        inOrder(node->left, ans);

        // push node data
        ans.push_back(node->val);

        // call right
        inOrder(node->right, ans);
        return;
    }

public:
    vector<int> inorderTraversal(TreeNode *root)
    {
        vector<int> ans;
        inOrder(root, ans);
        return ans;
    }
};

int main()
{
    Solution S;
}