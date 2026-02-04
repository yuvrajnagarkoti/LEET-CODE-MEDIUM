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

    void preorder(TreeNode *root,vector<int> &ans,int level)
    {
        int n = ans.size();
        if(root == NULL)
            return;
        if( n<level)
            ans.push_back(root->val);
        if( n >= level )
            ans[level-1] = max(ans[level-1],root->val);
        
        preorder(root->left,ans,level+1);
        preorder(root->right,ans,level+1);
    }
    vector<int> largestValues(TreeNode* root)
    {
        vector<int> ans;
        preorder(root,ans,1);

        return ans;
    }
};