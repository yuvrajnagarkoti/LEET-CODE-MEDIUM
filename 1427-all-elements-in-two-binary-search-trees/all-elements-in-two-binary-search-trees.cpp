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

    void dfs(TreeNode *root,vector<int> &ans)
    {
        if(root == NULL)
            return;
        
        dfs(root->left,ans);
        ans.push_back(root->val);
        dfs(root->right,ans);
    }
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2)
    {
        vector<int> ans1;
        vector<int> ans2;
        dfs(root1,ans1);
        dfs(root2,ans2);

        int i=0,n1=ans1.size();
        int j=0,n2=ans2.size();
        vector<int> ans;
        while(i<n1 && j<n2)
        {
            if(ans1[i] < ans2[j])
                ans.push_back(ans1[i++]);
            else
                ans.push_back(ans2[j++]);
        }
        while(i<n1)
            ans.push_back(ans1[i++]);
        while(j<n2)
            ans.push_back(ans2[j++]);
        
        return ans;
    }
};