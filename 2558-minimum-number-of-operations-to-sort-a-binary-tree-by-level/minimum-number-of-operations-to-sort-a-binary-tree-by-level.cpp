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

    int minswaps(vector<int> nums)
    {
        int count=0;
        vector<int> temp(nums.begin(),nums.end());
        sort(temp.begin(),temp.end());
        map<int,int> mpp;
        int n=nums.size();

        for(int i=0;i<n;i++)
        {
            mpp[nums[i]]=i;
        }

        for(int i=0;i<n;i++)
        {
            if( nums[i] != temp[i] )
            {
                count++;
                int cidx = mpp[temp[i]];
                mpp[nums[i]]=cidx;
                mpp[temp[i]]=i;
                swap( nums[i],nums[cidx] );
                
            }
        }
        return count;
    }

    int minimumOperations(TreeNode* root)
    {
        vector<vector<int>> bfs;
        queue<TreeNode*> q;
        q.push(root);
        while( !q.empty() )
        {
            vector<int> t;
            int n = q.size();
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
        int ans = 0;
        for(int i=1;i<bfs.size();i++)
        {
            ans = ans + minswaps(bfs[i]);
        }
        if(ans < 0)
            return 0;
        
        return ans;
    }
};