#include <iostream>

using namespace std;

// https://leetcode.com/problems/two-sum-iv-input-is-a-bst/

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
    stack<TreeNode *> asc;
    stack<TreeNode *> dsc;

    // creates sorted Stack in asecending
    TreeNode *getSmall()
    {
        if (asc.empty())
        {
            return nullptr;
        }

        TreeNode *small = asc.top();
        asc.pop();

        TreeNode *rightChild = small->right;
        while (rightChild)
        {
            asc.push(rightChild);
            rightChild = rightChild->left;
        }

        return small;
    }

    // creates sorted Stack in descending
    TreeNode *getBig()
    {
        if (dsc.empty())
        {
            return nullptr;
        }

        TreeNode *big = dsc.top();
        dsc.pop();

        TreeNode *leftChild = big->left;
        while (leftChild)
        {
            dsc.push(leftChild);
            leftChild = leftChild->right;
        }

        return big;
    }

public:
    bool findTarget(TreeNode *root, int target)
    {
        if (!root)
            return false;

        TreeNode *temp = root;
        while (temp)
        {
            asc.push(temp);
            temp = temp->left;
        }

        temp = root;
        while (temp)
        {
            dsc.push(temp);
            temp = temp->right;
        }

        TreeNode *low = getSmall();
        TreeNode *high = getBig();

        while (low && high && low != high && low->val < high->val)
        {
            int sum = low->val + high->val;

            if (sum == target)
            {
                return true;
            }

            if (sum > target)
            {
                high = getBig();
            }
            else
            {
                low = getSmall();
            }
        }

        return false;
    }
};

int main()
{
    Solution S;
}