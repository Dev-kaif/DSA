#include <iostream>

using namespace std;

// https://leetcode.com/problems/search-in-a-binary-search-tree/

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
public:
    TreeNode *searchBST(TreeNode *root, int val)
    {

        if (root == nullptr)
        {
            return nullptr;
        }

        int rootVal = root->val;

        if (rootVal == val)
        {
            return root;
        }

        if (val > rootVal)
        {
            return searchBST(root->right, val);
        }

        // last case where rootVal > val
        return searchBST(root->left, val);
    }
};

int main()
{
    Solution S;
}