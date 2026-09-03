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
    int dfs(TreeNode *root,int i)
    {
        if(root == NULL)
            return i;
        
        int t1 = dfs(root->left,i+1);
        int t2 = dfs(root->right,i+1);

        return max(t1,t2);
    }
    
    int maxDepth(TreeNode* root)
    {
        int ans= dfs(root,0);
        return ans;    
    }
};