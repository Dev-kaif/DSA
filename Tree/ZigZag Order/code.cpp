#include <iostream>

using namespace std;

// https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/

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
    vector<vector<int>> zigzagLevelOrder(TreeNode *root)
    {
        if (root == nullptr)
        {
            return {};
        }

        vector<vector<int>> res;
        queue<TreeNode *> q;
        bool leftToRight = true;

        q.push(root);

        while (!q.empty())
        {
            int steps = q.size();
            vector<int> temp(steps);

            int end = steps - 1;

            for (int start = 0; start < steps; start++)
            {
                TreeNode *t = q.front();
                q.pop();

                // calculate the index
                // if its left -> right : place it at start
                // if its right -> left : place it at end
                int index = leftToRight ? start : end - start;
                temp[index] = t->val;

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
            leftToRight = !leftToRight;
        }

        return res;
    }
};

int main()
{
    Solution S;
}