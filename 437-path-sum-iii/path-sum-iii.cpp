/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     long long val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(long long x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(long long x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
    public:
    long long ans=0;

    void dfs(TreeNode *root,long long target,vector<long long> temp)
    {
        if(root == NULL)
            return;
        
        if(root->val == target)
            ans++;
    
        for(long long i=0;i<temp.size();i++)
        {
            temp[i] = temp[i] + root->val;

            if(temp[i] == target)
                ans++;
        }

        temp.push_back(root->val);

        dfs(root->left,target,temp);
        dfs(root->right,target,temp);
    }

    long long pathSum(TreeNode* root, long long target)
    {
        vector<long long> temp; // sum of all the a-b

        dfs(root,target,temp);

        return ans;
    }
};