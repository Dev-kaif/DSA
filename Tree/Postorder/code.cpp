#include <iostream>

using namespace std;

// https://leetcode.com/problems/binary-tree-postorder-traversal/

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
    void postOrder(TreeNode *node, vector<int> &ans)
    {
        if (node == nullptr)
            return;

        // call left
        postOrder(node->left, ans);

        // call right
        postOrder(node->right, ans);

        // node data to ans
        ans.push_back(node->val);
        return;
    }

public:
    vector<int> postorderTraversal(TreeNode *root)
    {
        vector<int> ans;
        postOrder(root, ans);
        return ans;
    }
};

int main()
{
    Solution S;
}