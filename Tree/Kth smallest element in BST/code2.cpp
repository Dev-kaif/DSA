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
    void dfs(TreeNode *node, int target, int &count, TreeNode *&ans)
    {
        if (!node || ans != nullptr)
        {
            return;
        }

        // visit left first because we want the smallest values first
        dfs(node->left, target, count, ans);

        // current node is the next smallest element
        count++;

        // if we reached the kth smallest, store the answer
        if (count == target)
        {
            ans = node;
        }

        // visit the right subtree to check for depth
        dfs(node->right, target, count, ans);
    }

public:
    int kthSmallest(TreeNode *root, int k)
    {
        TreeNode *ans = nullptr;
        int count = 0;
        dfs(root, k, count, ans);

        return ans->val;
    }
};

int main()
{
    Solution S;
}