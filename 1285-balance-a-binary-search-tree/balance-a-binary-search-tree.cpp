/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution
{
public:
    void inorder(TreeNode* root, vector<TreeNode*>& dfs)
    {
        if (!root) return;
        inorder(root->left, dfs);
        dfs.push_back(root);
        inorder(root->right, dfs);
    }

    TreeNode* buildtree(vector<TreeNode*>& dfs, int low, int high)
    {
        if (low > high) return NULL;

        int mid = low + (high - low) / 2;
        TreeNode* root = dfs[mid];

        root->left = buildtree(dfs, low, mid - 1);
        root->right = buildtree(dfs, mid + 1, high);

        return root;
    }

    TreeNode* balanceBST(TreeNode* root)
    {
        vector<TreeNode*> dfs;
        inorder(root, dfs);
        return buildtree(dfs, 0, dfs.size() - 1);
    }
};