#include <iostream>

using namespace std;

// 	https://leetcode.com/problems/same-tree/description/

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

        bool r1 = isSameTree(root1->left, root2->left);
        bool r2 = isSameTree(root1->right, root2->right);

        if (r1 == true && r2 == true)
        {
            return true;
        }

        return false;
    }
};

int main()
{
    Solution S;
}