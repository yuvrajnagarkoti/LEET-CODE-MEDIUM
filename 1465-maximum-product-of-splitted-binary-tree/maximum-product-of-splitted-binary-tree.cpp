class Solution
{
public:
    const long long MOD = 1000000007;

    long long ans = 0;
    long long totalSum = 0;

    long long dfs(TreeNode* root)
    {
        if (!root) return 0;

        long long left = dfs(root->left);
        long long right = dfs(root->right);

        long long subSum = left + right + root->val;

        ans = max(ans, subSum * (totalSum - subSum));

        return subSum;
    }

    int maxProduct(TreeNode* root)
    {
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty())
        {
            TreeNode* temp = q.front();
            q.pop();

            totalSum += temp->val;

            if (temp->left) q.push(temp->left);
            if (temp->right) q.push(temp->right);
        }

        dfs(root);

        return ans % MOD;
    }
};