#include <iostream>

using namespace std;

// https://leetcode.com/problems/symmetric-tree/

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
    bool isSameTree(TreeNode *root1, TreeNode *root2)
    {
        if (root1 == nullptr && root2 == nullptr)
        {
            return true;
        }

        if (root1 == nullptr || root2 == nullptr)
        {
            return false;
        }

        if (root1->val != root2->val)
        {
            return false;
        }

        bool r1 = isSameTree(root1->left, root2->right);
        bool r2 = isSameTree(root1->right, root2->left);


        return r1 || r2;
    }

public:
    bool isSymmetric(TreeNode *root)
    {
        return isSameTree(root->left, root->right);
    }
};

int main()
{
    Solution S;
}