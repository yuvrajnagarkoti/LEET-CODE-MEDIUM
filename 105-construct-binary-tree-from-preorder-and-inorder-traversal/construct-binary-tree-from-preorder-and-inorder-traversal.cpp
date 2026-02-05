class Solution {
public:
    unordered_map<int,int> inorderIndex;
    int preIndex = 0;

    TreeNode* build(int left, int right, vector<int>& preorder) {
        if (left > right)
            return NULL;

        int rootVal = preorder[preIndex++];
        TreeNode* root = new TreeNode(rootVal);
        int mid = inorderIndex[rootVal];

        root->left = build(left, mid - 1, preorder);
        root->right = build(mid + 1, right, preorder);

        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for (int i = 0; i < inorder.size(); i++)
            inorderIndex[inorder[i]] = i;

        return build(0, inorder.size() - 1, preorder);
    }
};
