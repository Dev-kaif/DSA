#include <iostream>

using namespace std;

// https://leetcode.com/problems/sum-root-to-leaf-numbers/description/

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

    void digits(TreeNode *node, int sum, int &ans)
    {
        if (!node)
        {
            return;
        }

        sum = sum * 10 + node->val;

        if (leaf(node))
        {
            ans += sum;
            return;
        }

        digits(node->left, sum, ans);
        digits(node->right, sum, ans);
    }

public:
    int sumNumbers(TreeNode *root)
    {
        if (!root)
        {
            return 0;
        }

        int ans = 0;

        digits(root, 0, ans);

        return ans;
    }
};

int main()
{
    Solution S;
}