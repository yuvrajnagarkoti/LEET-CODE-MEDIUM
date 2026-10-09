class Solution {
public:
    bool dfs(TreeNode* temp, long long low, long long high)
    {
        if (temp == NULL)
            return true;

        if (temp->val <= low || temp->val >= high)
            return false;

        return dfs(temp->left, low, temp->val) && dfs(temp->right, temp->val, high);
    }

    bool isValidBST(TreeNode* root)
    {
        return dfs(root, LLONG_MIN, LLONG_MAX);
    }
};