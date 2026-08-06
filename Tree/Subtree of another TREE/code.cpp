#include <iostream>

using namespace std;

// https://leetcode.com/problems/subtree-of-another-tree/

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
    bool sameTree(TreeNode *node, TreeNode *subRoot)
    {

        if (node == nullptr && subRoot == nullptr)
        {
            return true;
        }

        if (node == nullptr || subRoot == nullptr)
        {
            return false;
        }

        if (node->val != subRoot->val)
        {
            return false;
        }

        return sameTree(node->left, subRoot->left) &&
               sameTree(node->right, subRoot->right);
    }

public:
    bool isSubtree(TreeNode *root, TreeNode *subRoot)
    {

        if (subRoot == nullptr)
        {
            return true;
        }

        if (root == nullptr)
        {
            return false;
        }

        if (sameTree(root, subRoot))
        {
            return true;
        }

        return isSubtree(root->left, subRoot) ||
               isSubtree(root->right, subRoot);
    }
};

int main()
{
    Solution S;
}