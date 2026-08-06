class Solution
{
    public:
    vector<vector<int>> ans;
    void rec(int k,vector<int> temp,int sum,vector<int>& candidates, int target)
    {
        
        temp.push_back(candidates[k]);
        sum = sum + candidates[k];

        if(sum > target)
            return;
        if(sum == target)
        {
            ans.push_back(temp);
            return;
        }

        for(int i=k;i<candidates.size();i++)
        {
            rec(i,temp,sum,candidates,target);
        }
        
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target)
    {
        int sum=0;
        vector<int> temp;
        for(int i=0;i<candidates.size();i++)
        {
            rec(i,temp,sum,candidates,target);
        }
        return ans;
    }
};