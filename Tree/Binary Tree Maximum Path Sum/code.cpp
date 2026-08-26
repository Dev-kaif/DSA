#include <iostream>

using namespace std;

// https://leetcode.com/problems/binary-tree-inorder-traversal/

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
    int dfs(TreeNode*node,int&ans){
        
    }
public:
    int maxPathSum(TreeNode *root)
    {
        int ans = INT_MIN;
        dfs(root, ans);

        return ans;
    }
};

int main()
{
    Solution S;
}