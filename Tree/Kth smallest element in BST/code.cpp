#include <iostream>

using namespace std;

// https://leetcode.com/problems/kth-smallest-element-in-a-bst/

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
    // Inorder traversal of a BST gives elements in sorted order.
    void inOrder(TreeNode *node, vector<int> &ans)
    {
        if (!node)
        {
            return;
        }

        inOrder(node->left, ans);
        ans.push_back(node->val);
        inOrder(node->right, ans);
    }

public:
    int kthSmallest(TreeNode *root, int k)
    {
        vector<int> ans;
        inOrder(root, ans);

        // Return the k-th smallest element.
        // Subtract 1 because vector indexing starts from 0.
        return ans[k - 1];
    }
};

int main()
{
    Solution S;
}