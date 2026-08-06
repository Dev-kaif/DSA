#include <iostream>

using namespace std;

// https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/

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
    int lca(TreeNode *node, TreeNode *p, TreeNode *q, TreeNode *&ans)
    {

        if (node == nullptr)
        {
            return 0;
        }

        int self = (node == p) || (node == q);

        int val1 = lca(node->left, p, q, ans);
        int val2 = lca(node->right, p, q, ans);

        int total = val1 + val2 + self;

        if (total == 2 && ans == nullptr)
        {
            ans = node;
        }

        return total;
    }

public:
    TreeNode *lowestCommonAncestor(TreeNode *node, TreeNode *p, TreeNode *q)
    {

        if (node == nullptr)
        {
            return nullptr;
        }

        TreeNode *ans = nullptr;
        lca(node, p, q, ans);
        return ans;
    }
};

int main()
{
    Solution S;
}