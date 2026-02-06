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

    unordered_map <int,int> mpp;
    int index = 0;

    TreeNode* maketree(int left,int right,vector<int> &postorder)
    {
        if(left > right)
            return NULL;
        
        int val = postorder[index--];
        TreeNode * node = new TreeNode(val);
        int mid = mpp[val];

        node->right = maketree(mid+1,right,postorder);
        node->left = maketree(left,mid-1,postorder);

        return node;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder)
    {
        int n = inorder.size();
        for(int i=0;i<n;i++)
        {
            mpp[inorder[i]] = i;
        }
        index = n-1;
        return maketree(0,n-1,postorder);
    }
};