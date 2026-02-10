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

    void dfs(TreeNode *&prev,TreeNode *root,int val)
    {
        if(root == NULL)    
            return;
        
        prev = root;
        if(root-> val > val)
            dfs(prev,root->left,val);
        else
            dfs(prev,root->right,val);
    }

    TreeNode* insertIntoBST(TreeNode* root, int val)
    {
        TreeNode *prev = root;
        dfs(prev,root,val);
        if(root == NULL)
            return new TreeNode(val);
        
        if(prev->val > val)
            prev->left = new TreeNode(val);
        else
            prev->right = new TreeNode(val);
        return root;
    }
};