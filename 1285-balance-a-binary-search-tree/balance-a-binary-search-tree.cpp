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

    void inorder(TreeNode* root,vector<TreeNode*> &dfs)
    {
        if(root == NULL)
            return;
        
        inorder(root->left,dfs);
        dfs.push_back(root);
        inorder(root->right,dfs);
    }

    void buildtree(TreeNode *&ans,vector<TreeNode*> &dfs,int low,int high)
    {
        if(low > high)
        {
            ans=NULL;
            return;
        }
        
        int mid = low + (high-low)/2;
        ans = new TreeNode(dfs[mid]->val);
        buildtree(ans->left,dfs,low,mid-1);
        buildtree(ans->right,dfs,mid+1,high);
    }

    TreeNode* balanceBST(TreeNode* root)
    {
        vector<TreeNode*> dfs;
        inorder(root,dfs);

        TreeNode *ans = NULL;
        buildtree(ans,dfs,0,dfs.size()-1);

        return ans;
    }
};