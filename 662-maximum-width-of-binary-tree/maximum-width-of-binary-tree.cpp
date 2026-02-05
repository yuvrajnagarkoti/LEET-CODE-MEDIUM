class Solution {
public:
    int widthOfBinaryTree(TreeNode* root)
    {
        int ans = 0;
        queue<pair<TreeNode*, long long>> q;   // FIX 1: use long long
        q.push({root, 0});

        while(!q.empty())
        {
            int n = q.size();
            long long start = q.front().second;
            long long end = q.back().second;

            ans = max(ans, (int)(end - start + 1));

            for(int i = 0; i < n; i++)
            {
                auto [node, num] = q.front();
                q.pop();

                num -= start;   // FIX 2: normalize index

                if(node->left)
                    q.push({node->left, 2*num + 1});
                if(node->right)
                    q.push({node->right, 2*num + 2});
            }
        }
        return ans;
    }
};
