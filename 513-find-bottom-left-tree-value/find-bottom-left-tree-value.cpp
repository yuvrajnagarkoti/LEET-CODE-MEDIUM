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

    void preorder(TreeNode *root,pair<int,int> &ans,int level)
    {
        if(root == NULL)
            return;
        
        if(ans.second < level)
        {
            
            ans.first = root->val;
            ans.second = level;
        }
        
        preorder(root->left,ans,level+1);
        preorder(root->right,ans,level+1);
    }
    int findBottomLeftValue(TreeNode* root)
    {
        pair<int,int> ans = {0,0};
        preorder(root,ans,1);

        return ans.first;
    }
};