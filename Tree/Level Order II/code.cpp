#include <iostream>

using namespace std;

// https://leetcode.com/problems/binary-tree-level-order-traversal-ii/

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
    vector<vector<int>> levelOrderBottom(TreeNode *root)
    {
        if (root == nullptr)
        {
            return {};
        }

        vector<vector<int>> res;

        queue<TreeNode *> q;
        q.push(root);

        while (!q.empty())
        {
            int steps = q.size();
            vector<int> temp;

            while (steps--)
            {
                TreeNode *t = q.front();
                q.pop();
                temp.push_back(t->val);

                if (t->left != nullptr)
                {
                    q.push(t->left);
                }

                if (t->right != nullptr)
                {
                    q.push(t->right);
                }
            }

            res.push_back(temp);
        }

        reverse(res.begin(), res.end());
        return res;
    }
};

int main()
{
    Solution S;
}