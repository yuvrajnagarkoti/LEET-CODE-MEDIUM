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
    vector<vector<int>> ans;

    void dfs(TreeNode *root,int &target,int cursum,vector<int> temp)
    {
        if(root == NULL)
            return;
        
        cursum += root->val;
        temp.push_back(root->val);

        if(root->left == NULL && root->right == NULL)
        {
            if(cursum == target)
                ans.push_back(temp);
            return;
        }

        dfs(root->left,target,cursum,temp);
        dfs(root->right,target,cursum,temp);
    }

    vector<vector<int>> pathSum(TreeNode* root, int targetSum)
    {
        vector<int> temp;

        dfs(root,targetSum,0,temp);

        return ans;
    }
};