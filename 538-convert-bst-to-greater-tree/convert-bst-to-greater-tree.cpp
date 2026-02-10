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

    void inorder(TreeNode *root,vector<int> &dfs)
    {
        if(root == NULL)
            return;
        
        inorder(root->left,dfs);
        dfs.push_back(root->val);
        inorder(root->right,dfs);

    }

    void refill(TreeNode *&root,map<int,int> &mpp,vector<int> &postfix)
    {
        if(root==NULL)
            return;
        
        refill(root->left,mpp,postfix);
        int index = mpp[root->val];
        root->val = postfix[index];
        refill(root->right,mpp,postfix);
    }

    TreeNode* convertBST(TreeNode* root)
    {
        vector<int> dfs;
        inorder(root,dfs);
        int n = dfs.size();
        vector<int> postfix(n);
        int sum=0;
        for(int i=n-1;i>=0;i--)
        {
            sum=sum+dfs[i];
            postfix[i]=sum;
        }
        map<int,int> mpp;
        for(int i=0;i<n;i++)
        {
            mpp[dfs[i]]=i;
        }
        refill(root,mpp,postfix);

        return root;
    }
};