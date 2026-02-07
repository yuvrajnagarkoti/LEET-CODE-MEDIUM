class Solution
{
public:
    void inorder(TreeNode *root, vector<TreeNode*> &pre)
    {
        if(root == NULL)
            return;

        inorder(root->left, pre);
        pre.push_back(root);
        inorder(root->right, pre);
    }

    void recoverTree(TreeNode* root)
    {
        vector<TreeNode*> pre;
        inorder(root, pre);

        TreeNode* first = NULL;
        TreeNode* second = NULL;

        int n = pre.size();
        for(int i = 1; i < n; i++)
        {
            if(pre[i-1]->val > pre[i]->val)
            {
                if(first == NULL)
                    first = pre[i-1];   // first violation
                second = pre[i];        // second violation (keep updating)
            }
        }

        if(first && second)
            swap(first->val, second->val);
    }
};
