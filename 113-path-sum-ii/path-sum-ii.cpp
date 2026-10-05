class Solution
{
public:
    vector<vector<int>> ans;
    vector<int> temp;

    void dfs(TreeNode *root, int &target, int cursum)
    {
        if(root == NULL)
            return;

        cursum += root->val;
        temp.push_back(root->val);

        if(root->left == NULL && root->right == NULL)
        {
            if(cursum == target)
                ans.push_back(temp);

            temp.pop_back();   // ✅ backtrack
            return;
        }

        dfs(root->left, target, cursum);
        dfs(root->right, target, cursum);

        temp.pop_back();       // backtrack
    }

    vector<vector<int>> pathSum(TreeNode* root, int targetSum)
    {
        dfs(root, targetSum, 0);

        return ans;
    }
};