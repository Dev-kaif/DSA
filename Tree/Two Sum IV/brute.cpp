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

    // creates sorted array order of tree valus
    void inOrder(TreeNode *node, vector<int> &ans)
    {
        if (node == nullptr)
        {
            return;
        }

        // call left
        inOrder(node->left, ans);

        // push node data
        ans.push_back(node->val);

        // call right
        inOrder(node->right, ans);
        return;
    }

    // two sum as needed
    bool twoSum(vector<int> &a, int target)
    {
        int low = 0;
        int high = a.size() - 1;

        while (low < high)
        {
            int sum = a[low] + a[high];

            if (sum == target)
            {
                return true;
            }
            if (sum > target)
            {
                high--;
            }
            else
            {
                low++;
            }
        }
        return false;
    }

public:
    bool findTarget(TreeNode *root, int k)
    {

        if (root == nullptr)
        {
            return false;
        }

        vector<int> ans;
        inOrder(root, ans);

        return twoSum(ans, k);
    }
};

int main()
{
    Solution S;
}