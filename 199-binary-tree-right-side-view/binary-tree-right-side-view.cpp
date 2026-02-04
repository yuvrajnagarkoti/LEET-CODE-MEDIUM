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
class Solution {
public:
    vector<int> rightSideView(TreeNode* root)
    {
        vector<vector<int>> bfs;
        vector<int> ans;
        queue<TreeNode*> q;
        if(root == NULL)
            return ans;
        
        q.push(root);
        while( !q.empty())
        {
            int n=q.size();
            vector<int> t;
            for(int i=0;i<n;i++)
            {
                TreeNode *temp = q.front();
                t.push_back(temp->val);
                q.pop();
                if(temp->left != NULL)
                    q.push(temp->left);
                if(temp->right != NULL)
                    q.push(temp->right);
            }
            bfs.push_back(t);
        }
        for(int i=0;i<bfs.size();i++)
        {
            int n=bfs[i].size();
            ans.push_back(bfs[i][n-1]);
        }
        return ans;
    }
};