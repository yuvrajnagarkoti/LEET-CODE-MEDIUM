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
    map<int,int> mpp;
    
    void preorder(TreeNode* root,int level)
    {
        if(root == NULL)
            return;
        
        mpp[level] += root->val;
        preorder(root->left,level+1);
        preorder(root->right,level+1);
    }

    int maxLevelSum(TreeNode* root)
    {
        preorder(root,1);

        int ans=INT_MIN;
        int level=0;
        for(auto it:mpp)
        {
            if(it.second > ans)
            {
                ans=it.second;
                level=it.first;
            }
        }
        return level;
    }
};